#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>

using namespace std;

class Request{
    string _method;
    string _path;
    string _key;
    string _value;
public:
    Request();
    Request(string request);
    ~Request();

    string method();
    string path();
    string key();
    string value();
};

#endif //REQUEST_H