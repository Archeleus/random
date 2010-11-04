#!/usr/bin/env python3.1
# -*- coding: utf-8 -*-
#Alex John 2010

from urllib.request import urlopen
from xml.dom import minidom

def main():
    loc = "http://sickipedia.org/xml/getjokes/random"
    doc = minidom.parse(urlopen(loc))
    #joke = "Hello <br />I am a git<br />. yayaya"
    joke = (doc.childNodes[1].childNodes[3].childNodes[1].childNodes[1].data)
    tokens = joke.split("<br />");
    for s in tokens:
        print(s)
    file = open('/home/alex/sickipedia_log.txt', 'a')
    file.write(joke + "\n-----------------\n\n")
    file.close()
if __name__ == "__main__":
    main()