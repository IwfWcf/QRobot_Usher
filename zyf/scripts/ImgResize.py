#coding=utf-8

import sys, math, Image
import cv2
import cv2.cv as cv

def Distance(p1,p2):
  dx = p2[0] - p1[0]
  dy = p2[1] - p1[1]
  return math.sqrt(dx*dx+dy*dy)

def ScaleRotateTranslate(image, angle, center = None, new_center = None, scale = None, resample=Image.BICUBIC):
  if (scale is None) and (center is None):
    return image.rotate(angle=angle, resample=resample)
  nx,ny = x,y = center
  sx=sy=1.0
  if new_center:
    (nx,ny) = new_center
  if scale:
    (sx,sy) = (scale, scale)
  cosine = math.cos(angle)
  sine = math.sin(angle)
  a = cosine/sx
  b = sine/sx
  c = x-nx*a-ny*b
  d = -sine/sy
  e = cosine/sy
  f = y-nx*d-ny*e
  return image.transform(image.size, Image.AFFINE, (a,b,c,d,e,f), resample=resample)

def CropFace(image, eye_left=(0,0), eye_right=(0,0), offset_pct=(0.2,0.2), dest_sz = (70,70)):
  # calculate offsets in original image
  offset_h = math.floor(float(offset_pct[0])*dest_sz[0])
  offset_v = math.floor(float(offset_pct[1])*dest_sz[1])
  # get the direction
  eye_direction = (eye_right[0] - eye_left[0], eye_right[1] - eye_left[1])
  # calc rotation angle in radians
  rotation = -math.atan2(float(eye_direction[1]),float(eye_direction[0]))
  # distance between them
  dist = Distance(eye_left, eye_right)
  # calculate the reference eye-width
  reference = dest_sz[0] - 2.0*offset_h
  # scale factor
  scale = float(dist)/float(reference)
  # rotate original around the left eye
  image = ScaleRotateTranslate(image, center=eye_left, angle=rotation)
  # crop the rotated image
  crop_xy = (eye_left[0] - scale*offset_h, eye_left[1] - scale*offset_v)
  crop_size = (dest_sz[0]*scale, dest_sz[1]*scale)
  image = image.crop((int(crop_xy[0]), int(crop_xy[1]), int(crop_xy[0]+crop_size[0]), int(crop_xy[1]+crop_size[1])))
  # resize it
  image = image.resize(dest_sz, Image.ANTIALIAS)
  return image

def detect(img, cascade):
    rects = cascade.detectMultiScale(img, scaleFactor=1.3, minNeighbors=4, minSize=(30, 30), flags = cv.CV_HAAR_SCALE_IMAGE)
    if len(rects) == 0:
        return []
    return rects

if __name__ == "__main__":
  fi = open("database.csv", "r")
  cascade_fn = "haarcascade_frontalface_alt.xml"
  cascade = cv2.CascadeClassifier(cascade_fn)
  nested_fn = "haarcascade_eye.xml"
  nested = cv2.CascadeClassifier(nested_fn)

  # for line in fi:
  #   arr = line.split(';')
  #   image = cv2.imread(arr[0])
  #   rects = detect(image, cascade)
  #   x1, y1, x2, y2 = rects[0]
  #   roi = image[y1:y2, x1:x2]
  #   cv2.imwrite(arr[0], roi)
  #   image = Image.open(arr[0])
  #   image.resize((70, 70), Image.ANTIALIAS).save(arr[0])

  for line in fi:
    arr = line.split(';')
    image = cv2.imread(arr[0])
    rects = detect(image, cascade)
    x1, y1, w, h = rects[0]
    x2 = x1 + w
    y2 = y1 + h
    x, y = x1, y1
    roi = image[y1:y2, x1:x2]
    subrects = detect(roi, nested)
    x1, y1, w, h = subrects[0]
    x1 += w / 2 + x
    y1 += h / 2 + y
    x2, y2, w, h = subrects[1]
    x2 += w / 2 + x
    y2 += h / 2 + y
    if x1 > x2:
      x1, x2, y1, y2 = x2, x1, y2, y1
    image = Image.open(arr[0])
    CropFace(image, eye_left = (x1, y1), eye_right = (x2, y2)).save(arr[0])