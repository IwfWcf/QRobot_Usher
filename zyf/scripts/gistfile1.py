#coding=utf-8 

import json
import os
import time
import requests
import Image
from StringIO import StringIO
from requests.exceptions import ConnectionError

def go(query, path):
  """Download full size images from Google image search.

  Don't print or republish images without permission.
  I used this to train a learning algorithm.
  """
  BASE_URL = 'https://www.googleapis.com/customsearch/v1?key=AIzaSyDmrR_odkcxnEfbDXRHC_uMve5qa0_jchg&cx=004699099742620932646:rrlff1m-nma&q=' + query + '&imgSize=xxlarge&imgType=face&searchType=image'

  # print BASE_URL

  BASE_PATH = os.path.join(path, query)

  # print BASE_PATH

  if not os.path.exists(BASE_PATH):
    os.makedirs(BASE_PATH)

  start = 1 # Google's start query string parameter for pagination.
  while start <= 10: # Google will only return a max of 56 results.
    r = requests.get(BASE_URL)
    for i, image_info in enumerate(json.loads(r.text)['items']):
      url = image_info['link']
      try:
        image_r = requests.get(url)
      except ConnectionError, e:
        print 'could not download %s' % url
        continue

      # Remove file-system path characters from name.
      # title = image_info['title'].replace('/', '').replace('\\', '')

      file = open(os.path.join(BASE_PATH, '%d.jpg') % i, 'wb')
      try:
        Image.open(StringIO(image_r.content)).save(file, 'JPEG')
      except IOError, e:
        # Throw away some gifs...blegh.
        print 'could not save %s' % url
      finally:
        file.close()

    # print start
    start += 10 # 10 images per page.

    # Be nice to Google and they'll be nice back :)
    time.sleep(1.5)

# Example use
go(u'韩庚', 'D:\\facedatabase')
go(u'林峰', 'D:\\facedatabase')
go(u'Hebe', 'D:\\facedatabase')
go(u'钟欣桐', 'D:\\facedatabase')