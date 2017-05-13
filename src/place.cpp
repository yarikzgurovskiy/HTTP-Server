#include <place.h>

Place::Place(){
    _id = -1;
    _name = "";
    _city = "";
    _year = -1;
}

Place::~Place() {}

Place::Place(int id, string name, string city, int year){
    _id = id;
    _name = name;
    _city = city;
    _year = year;
}

int Place::id(){ return _id; }
string Place::name(){ return _name; }
string Place::city(){ return _city; }
int Place::year(){ return _year; }
string Place::valueByField(string field){
    if(field == "id") return to_string(_id);
    if(field == "year") return to_string(_year);
    if(field == "name") return _name;
    if(field == "city") return _city;
    return "NOT FIELD";
}