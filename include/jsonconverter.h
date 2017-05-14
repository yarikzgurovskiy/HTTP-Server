/**
    @file
    @brief Module to convert data to Json string
*/
#ifndef JSONCONVERTER_H
#define JSONCONVERTER_H

#include <iostream>
#include <vector>
#include <place.h>

using namespace std;

/**
    @brief get server information
    @return string in Json format that contain information about server
*/
string convertServerInfo(void);

/**
    @brief get all places in Json fromat
    @param places - vector of Places to convert in Json
    @return string in Json format that contain information about all places
*/
string convertPlaces(vector<Place*> places);

/**
    @brief get places that specified filed equals specified value
    @param places - vector of Places to filter and convert in Json 
    @param key - field on which to filter places
    @param value - content of field to filter places
    @return string in Json format that contain information about server
*/
string convertPlacesByKey(vector<Place*> places, string key, string value);

/**
    @brief get information about file
    @param filePath - path to file
    @return string in Json format that contain information about file
*/
string convertFileInfo(string filePath);

/**
    @brief get information about file content
    @param filePath - path to file
    @return string in Json format that contain information about file content
*/
string convertFileContent(string filePath);

#endif //JSONCONVERTER_H