//
// Created by ws on 2021/3/6.
// Modified by jx on 2021/4/7.
//

#include "SearchServer.h"
#include <iostream>
#include <string>

using namespace std;

string SearchServer::getServerName() const {return this->serverName;}

void SearchServer::printInfo() const {
    cout << this->getServerName() << ": " << this->requestCnt << " requests." << endl;
}

void SearchServer::pushJobQueue(Request req) {
    if (!this->isLive) {
        cout << "Ohhh, the server is down and request is lost!" << endl;
        return;
    }
    this->requestQueue.push(req);

    // Todo: you are supposed to finish this function from here.
    // starts from here
    // You should get the load of this Request req 
    int incoming_load = req.requestLoad;
    // and add the load to the current load of this server.
    this->currentLoad += incoming_load;
    // Then, if the currentLoad is larger than maxLoad,
    if (currentLoad > maxLoad) {
        refuseToPush();
        cout << "Search server: " << serverName <<
         " is overloaded.\nCurrent load is " << currentLoad << endl;
         }
    // call refuseToPush() and print information.

    // ends here
    return;
}

Request SearchServer::handleJobQueue() {
    if (requestQueue.size() == 0) {
        Request temp(SEARCH, 0, 0); // generate one empty Request to resist memory leak
        return temp;
    }
    Request temp = requestQueue.front();
    requestQueue.pop();
    return temp;
}

Response SearchServer::process(Request req) {
    this->requestCnt += 1;
    Response res = Response(req.getRequestId());

    // Todo:  you are supposed to finish this function from here.
    // starts from here
    int tempload = currentLoad;
    currentLoad -= req.requestLoad;
    if (tempload > maxLoad && currentLoad <= maxLoad){
        cout << "Search server: " << serverName 
        << " is back.\nCurrent load is " << currentLoad << endl;
        goodToWork();
    }
    // You should update the currentLoad and update the status of this server if necessary.

    // ends here
    return res;
}