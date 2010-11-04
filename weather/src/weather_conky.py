#!/usr/bin/env python3.1
# -*- coding: utf-8 -*-
#Alex John 2010
#Depends on the Yahoo! Weather feed
#Python 3.1
#Do not copy paste as your own script. I spent half an hour searching through nodes.
#Tuesday 6th July 2010 - First Version 1.0
#Friday 16th July 2010 - Added a conversion function for temperature. Used in the end.
#import urllib

from urllib.request import urlopen
from xml.dom import minidom

def convf_c(temp):
    x = (((int(temp) - 32)*5)/9)
    return str(x)


def main():
    #print("This script is still in development, do not enter places that do not exist. The script will crash if you do. #Also, you need an active internet connection.")
    #print("Alex 2010 Weather script v1.1")
    #country = input("Enter your country: \n")
    #state = input("Enter your state: \n")
    #city = input("Enter your city: \n")
    appId = "xuWfL5_V34FPtPjIKRcw6ghWkDVQ75vJrG30hGWf8cCBp4VXr518XkIw_hsP7NKsWeJmf8nIxgZ8PsPjN.gc"
    #queryString = "http://where.yahooapis.com/v1/places.q('"+city+"+"+state+"+"+country+"')?appid="+appId+".xml"
    #doc = minidom.parse(urlopen(queryString))
    # if(int(doc.firstChild.attributes["yahoo:count"].value) > 0):
    woeid = 1062617        
    wdoc = minidom.parse(urlopen("http://weather.yahooapis.com/forecastrss?w="+woeid))
    title = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[1].firstChild.data
    date_time = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[11].attributes["date"].value
    cond = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[11].attributes["text"].value
    temp = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[11].attributes["temp"].value
    #nextDay = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[15].attributes["day"].value
    #nextDay_date = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[15].attributes["date"].value
    #nextDay_low = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[15].attributes["low"].value
    #nextDay_high = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[15].attributes["high"].value
    #nextDay_prediction = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[15].attributes["text"].value
    #nextnextDay = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[17].attributes["day"].value
    #nextnextDay_date = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[17].attributes["date"].value
    #nextnextDay_low = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[17].attributes["low"].value
    #nextnextDay_high = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[17].attributes["high"].value
    #nextnextDay_prediction = wdoc.firstChild.childNodes[1].childNodes[25].childNodes[17].attributes["text"].value
    credits = "Provided by The Weather Channel and obtained via Yahoo! Weather"
    print("Weather " + title)
    print(date_time)
    print("Temperature (F) : " + temp)
    print("Condition : " + cond)
      #  print("The next two days forecast -")
      #  print(nextDay + " " + nextDay_date)
     #   print("Low : " + nextDay_low + "\nHigh : " + nextDay_high + "\nPredicted Conditions : " + nextDay_prediction)
       # print(nextnextDay + " " + nextnextDay_date)
       # print("Low : " + nextnextDay_low + "\nHigh : " + nextnextDay_high + "\nPredicted Conditions : " + nextnextDay_prediction)
       # print("Temperature for today in degree C : " + convf_c(temp))
    #else:
     #   print("Place not found, make more sense next time. Exiting.")
if __name__ == "__main__":
    main()
