#ifndef PLACE_H
#define PLACE_H

#include <iostream>

using namespace std;

class Place{
    int _id;
    string _name;
    string _city;
    int _year;
public:
    Place();
    ~Place();
    Place(int id, string name, string city, int year);

    int id();
    string name();
    string city();
    int year();
    string valueByField(string field);
};

#endif //PLACE_H