#coding=utf-8 

import json
import os
import time
import requests
import Image
from StringIO import StringIO
from requests.exceptions import ConnectionError
import numpy as np
import cv2
import cv2.cv as cv

def detect(img, cascade):
    rects = cascade.detectMultiScale(img, scaleFactor=1.3, minNeighbors=4, minSize=(30, 30), flags = cv.CV_HAAR_SCALE_IMAGE)
    if len(rects) == 0:
        return []
    rects[:,2:] += rects[:,:2]
    return rects

def go(query, path):
  """Download full size images from Google image search.

  Don't print or republish images without permission.
  I used this to train a learning algorithm.
  """
  BASE_URL = 'https://www.googleapis.com/customsearch/v1?key=AIzaSyDmrR_odkcxnEfbDXRHC_uMve5qa0_jchg&cx=004699099742620932646:rrlff1m-nma&q=' + query + '&imgSize=large&imgType=face&searchType=image&start=%d'

  # print BASE_URL

  BASE_PATH = os.path.join(path, query)

  # print BASE_PATH

  if not os.path.exists(BASE_PATH):
    os.makedirs(BASE_PATH)

  cascade_fn = "haarcascade_frontalface_alt.xml"
  cascade = cv2.CascadeClassifier(cascade_fn)
  start = 1 # Google's start query string parameter for pagination.
  count = 0
  while count < 10: # Google will only return a max of 56 results.
    r = requests.get(BASE_URL.encode("utf-8") % start)
    for image_info in json.loads(r.text)['items']:
      url = image_info['link']
      try:
        image_r = requests.get(url)
      except ConnectionError, e:
        print 'could not download %s' % url
        continue

      # Remove file-system path characters from name.
      # title = image_info['title'].replace('/', '').replace('\\', '')

      filename = os.path.join(BASE_PATH, '%d.jpg') % count
      try:
        Image.open(StringIO(image_r.content)).save(filename)
        img = cv2.imread(filename.encode("gbk"))
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        gray = cv2.equalizeHist(gray)
        rects = detect(gray, cascade)
        if (len(rects) == 1):
          for x1, y1, x2, y2 in rects:
            roi = img[y1:y2, x1:x2]
            cv2.imwrite(filename.encode("gbk"), roi)
          count += 1
          if count == 10: break
      except IOError, e:
        # Throw away some gifs...blegh.
        print 'could not save %s' % url

    # print start
    start += 10 # 10 images per page.

    # Be nice to Google and they'll be nice back :)
    time.sleep(1.5)

if __name__ == '__main__':
  querys = [u'刘亦菲', u'姚笛', u'钟汉良', u'刘诗诗', u'范冰冰', u'宋茜', u'高圆圆', u'张根硕', u'杨幂', u'王力宏', u'张歆艺', u'吴奇隆', u'柳岩', u'唐嫣', u'金贤重', u'张雨绮', u'汤唯', u'周迅', u'孙俪', u'官恩娜', u'李准基', u'朴有天', u'韩庚', u'林峰', u'Hebe', u'钟欣桐']
  path = 'D:\\faceImage'
  for query in querys:
    go(query, path)