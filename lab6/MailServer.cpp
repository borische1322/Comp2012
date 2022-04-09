//
// Created by ws on 2021/3/2.
// Modified by jx on 2021/4/7.
//

#include "MailServer.h"
#include <iostream>
#include <string>

using namespace std;

string MailServer::getServerName() const { return this->serverName; }

void MailServer::printInfo() const {
    cout << this->getServerName() << ": " << this->requestCnt << " requests." << endl;
}

void MailServer::goodToWork() {
    // Todo: you are supposed to finish this function from here.
    // starts from here
    // You should judge if the server is live or not. If the server is not live,
    // set its status (isLive) to true and increase the liveServerNumber.
    if(!this->isLive) {this->isLive = true; liveServerNumber++;}

    // ends here
}

void MailServer::refuseToPush(){
    // Todo: you are supposed to finish this function from here.
    // starts from here
    // You should set its status (isLive) to false and decrease the liveServerNumber.
    this->isLive = false; liveServerNumber--;

    // ends here
}

void MailServer::pushJobQueue(Request req) {
    if (!this->isLive) {
        cout << "Ohhh, the server is down and request is lost!" << endl;
        return;
    }
    this->requestQueue.push(req);

    // Todo: you are supposed to finish this function from here.
    // starts from here
    // You should get the load of this Request req 
    // and add the load to the current load of this server.
    // Then, if the currentLoad is larger than maxLoad,
    // call refuseToPush() and print information.
    int incoming_load = req.requestLoad;
    
    this->currentLoad += incoming_load;

    if (currentLoad > maxLoad) {
        refuseToPush();
        cout << "Mail server: " << serverName <<
         " is overloaded.\nCurrent load is " << currentLoad << endl;
         }
    // ends here
    return;
}

Request MailServer::handleJobQueue() {
    if (requestQueue.size() == 0) {
        Request temp(EMAIL, 0, 0); // generate one empty Request to resist memory leak
        return temp;
    }
    Request temp = requestQueue.front();
    requestQueue.pop();
    return temp;
}

Response MailServer::process(Request req) {
    this->requestCnt += 1;
    Response res = Response(req.getRequestId());

    // Todo:  you are supposed to finish this function from here.
    // starts from here
    // You should update the currentLoad and update the status of this server if necessary.
    int tempload = currentLoad;
    currentLoad -= req.requestLoad;
    if (tempload > maxLoad && currentLoad <= maxLoad){
        cout << "Mail server: " << serverName 
        << " is back.\nCurrent load is " << currentLoad << endl;
        goodToWork();
    }
    // ends here
    return res;
}

