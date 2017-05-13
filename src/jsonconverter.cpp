#include <jsonconverter.h>
#include <iostream>
#include <vector>
#include <jansson.h>
#include <time.h>
#include <fstream>
#include <cctype>

using namespace std;

string readFile(string filePath);

string convertServerInfo(void){
    json_t * json = json_object();
    json_object_set_new(json, "title", json_string("Simple HTTP Server with my favorite places"));
    json_object_set_new(json, "developer",json_string( "Yaroslav Zghurovskyi"));
    //get current time
    time_t seconds = time(0);
    tm* timeinfo = localtime(&seconds);
    //set current time
    string t = string(asctime(timeinfo));
    const char * correct = t.erase(t.length() - 1, t.length()).c_str();
    json_object_set_new(json, "time", json_string(correct));
    char * str = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    string jsonString(str);
    free(str);
    json_decref(json);
    return jsonString;
}

string convertPlaces(vector<Place*> places){
    json_t * json = json_array();
    for(Place * place : places){
        json_t * pl = json_object();
        json_object_set_new(pl, "id", json_integer(place->id()));
        json_object_set_new(pl, "name", json_string(place->name().c_str()));
        json_object_set_new(pl, "year", json_integer(place->year()));
        json_object_set_new(pl, "city", json_string(place->city().c_str()));
        json_array_append(json, pl);
        json_decref(pl);
    }
    char * str = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    string jsonString(str);
    free(str);
    json_decref(json);
    return jsonString;
}

string convertPlacesByKey(vector<Place*> places, string key, string value){
    if(places[0]->valueByField(key) != "NOT FIELD"){
        json_t * json = json_array();
        bool isFound = false;
        for(Place * place : places){
            if(place->valueByField(key) == value){
                isFound = true;
                json_t * pl = json_object();
                json_object_set_new(pl, "id", json_integer(place->id()));
                json_object_set_new(pl, "name", json_string(place->name().c_str()));
                json_object_set_new(pl, "year", json_integer(place->year()));
                json_object_set_new(pl, "city", json_string(place->city().c_str()));
                json_array_append(json, pl);
                json_decref(pl);
            } 
        }
        char * str = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
        string jsonString(str);
        free(str);
        json_decref(json);
        if(!isFound) return "NOT FOUND";
        return jsonString;
    } else {
        return "NOT FOUND";
    }
    
}

string convertFileInfo(string filePath){
    string fileContent = readFile(filePath.c_str());
    if (fileContent == "NOT FOUND") {
        cerr << "Can't open file" << endl;
        return fileContent;
    }
    json_t * json = json_object();
    json_object_set_new(json, "filename", json_string( "data.txt"));
    json_object_set_new(json, "size(bytes)",json_integer(fileContent.size()));
    json_object_set_new(json, "content",  json_string(fileContent.c_str()));
    char * str = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    string jsonString(str);
    free(str);
    json_decref(json);
    return jsonString;
}
string convertFileContent(string filePath){
    string fileContent = readFile(filePath.c_str());
    if (fileContent == "NOT FOUND") {
        cerr << "Can't open file" << endl;
        return fileContent;
    }
    int upperLetters = 0;
    int lowerLetters = 0;
    int i = 0;
    while(fileContent[i]){
        if(isupper(fileContent[i])) upperLetters++;
        if(islower(fileContent[i])) lowerLetters++;
        i++;
    }
    json_t * json = json_object();
    json_object_set_new(json, "filename", json_string( "data.txt"));
    json_object_set_new(json, "leeters in upper case",json_integer(upperLetters));
    json_object_set_new(json, "letters in lower case",  json_integer(lowerLetters));
    char * str = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    string jsonString(str);
    free(str);
    json_decref(json);
    return jsonString;
}


string readFile(string filePath){
    string buf;
    string result = "";
    ifstream myfile (filePath);
    if (!myfile.is_open()){
        return "NOT FOUND";
    }
    while (!myfile.eof()){
        getline(myfile, buf);
        result += buf;
    }
    myfile.close();
    return result;
}