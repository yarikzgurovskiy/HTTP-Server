#ifndef JSONCONVERTER_H
#define JSONCONVERTER_H

#include <iostream>
#include <vector>
#include <place.h>

using namespace std;

string convertServerInfo(void);
string convertPlaces(vector<Place*> places);
string convertPlacesByKey(vector<Place*> places, string key, string value);
string convertFileInfo(string filePath);
string convertFileContent(string filePath);

#endif //JSONCONVERTER_H