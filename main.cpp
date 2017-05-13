#include <iostream>
#include <vector>
#include <progbase-cpp/net.h>

#include <request.h>
#include <response.h>
#include <place.h>

using namespace std;
using namespace progbase::net;

#define BUFFER_LENGTH 10000

vector<Place*> createPlaces(void);
void clearPlaces(vector<Place*> places);

int main(void){
    vector<Place*> places = createPlaces();
	const int serverPort = 8080;
    TcpListener listener;
    NetMessage message(BUFFER_LENGTH);
    try {
        listener.bind(IpAddress("127.0.0.1", serverPort));
        listener.start();
        while (true) {
            cout << ">> Waiting for clients at " << serverPort << "..." << endl;
            TcpClient * client = listener.accept();
            client->receive(message);
            cout << ">> Received: " << endl << message.dataAsString() << endl;
            Request * req = new Request(message.dataAsString());
            Response * res = new Response(req, places);
            message.setDataString(res->message());
            client->send(message);
            cout << ">> Response sent." << endl;
            delete client;
            delete req;
            delete res;
        }
    } catch(NetException const & exc) {
        cerr << exc.what() << endl;
    }
    clearPlaces(places);
    return 0;
}

vector<Place*> createPlaces(void){
    vector<Place*> places = {};
    places.push_back(new Place(123, "Golden Gates", "Kyiv", 1024));
    places.push_back(new Place(342, "Kamianets-Podilskyi Castle", "Kamianets-Podilskyi", 1928));
    places.push_back(new Place(36, "Lviv High Castle", "Lviv", 1250));
    places.push_back(new Place(456, "Lviv Town Hall", "Lviv", 1357));
    places.push_back(new Place(752, "Askania-Nova", "Kherson", 1898));
    places.push_back(new Place(285, "Sofiyivsky Park", "Uman", 1796));
    places.push_back(new Place(902, "NSC Olimpiyskiy", "Kyiv", 1923));
    return places;
}

void clearPlaces(vector<Place*> places){
    for(Place *place : places) delete place;
}

