/**
    @file
    @brief Data about favorite place
*/
#ifndef PLACE_H
#define PLACE_H

#include <iostream>

using namespace std;

/**
    @class Place
    @brief defines a favorite place
*/
class Place{
    int _id;
    string _name;
    string _city;
    int _year;
public:
    /**
        @brief default public constructor for Place
    */
    Place();

    /**
        @brief default public destructor for Place
    */
    ~Place();

    /**
        @brief public constructor for Place that fill all fields in Place
        @param id - unique number of Place
        @param name - name of Place
        @param city - locality of Place
        @param year - year of establishment of Place
    */
    Place(int id, string name, string city, int year);

    /**
        @brief get id of Place
        @return string that represented unique number of Place
    */
    int id();

    /**
        @brief get name of Place
        @return string that represented name of Place
    */
    string name();

    /**
        @brief get city of Place
        @return string that represented locality of Place
    */
    string city();

    /**
        @brief get year of Place
        @return string that represented year of establishment of Place
    */
    int year();

    /**
        @brief get value that contain specified filed of Place
        @param field - string that defines field which value returns
        @return string that represented value at specified field
    */
    string valueByField(string field);
};

#endif //PLACE_H