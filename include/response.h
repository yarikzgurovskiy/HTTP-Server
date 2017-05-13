#ifndef RESPONSE_H
#define RESPONSE_H

#include <request.h>
#include <place.h>
#include <iostream>
#include <vector>

using namespace std;

class Response{
    string _message;
public:
    Response();
    Response(Request * request, vector<Place*> places);
    ~Response();

    string message();
};

#endif //RESPONSE_H