//
// Created by jx on 2021/4/7.
//

#include "LBServer.h"
#include <iostream>
#include <string>

using namespace std;

string LoadBalancingServer::getServerName() const { return this->serverName; }

void LoadBalancingServer::printInfo() const {
    cout << "Load balancing server name is " << this->getServerName() << endl;
}

Response LoadBalancingServer::process(Request req) {
    RequestType type = req.getRequestType();
    switch (type) {
        case EMAIL :
            assignMailTasks(req);
            break;
        case SEARCH :
            assignSearchTasks(req);;
            break;
        default :
            // in this case, the request is unknown type,
            // we do not further process the request.
            break;
    }
    int id = req.getRequestId();
    Response fakeResponse(id); // fakeResponse is used merely to make the function complete
    return fakeResponse;       // This part is not the focus of this lab.
}

void LoadBalancingServer::assignSearchTasks(Request req) {
    if (this->searchServerNum == 0) {
        cout<< "There is no registered search server." <<endl;
        return;
    }
    if (this->searchServerIndex == this->searchServerNum ) {
        // index starts from the beginning
        this->searchServerIndex = 0;
    }

    this->registeredSearchServer[searchServerIndex].pushJobQueue(req);
    cout<< "LB server is assigning request with id " << req.getRequestId()
    << ", to search server " << registeredSearchServer[searchServerIndex].getServerName()
    << " , index = " << searchServerIndex <<endl;
    this->searchServerIndex++;
    return;
}

void LoadBalancingServer::assignMailTasks(Request req) {
    if (this->mailServerNum == 0) {
        cout<<"There is no registered email server."<<endl;
        return;
    }
    if (this->mailServerIndex == this->mailServerNum ) {
        // index starts from the beginning
        this->mailServerIndex = 0;
    }

    this->registeredMailServer[mailServerIndex].pushJobQueue(req);
    cout<< "LB server is assigning request with id "<< req.getRequestId()
    << ", to email server "<< registeredMailServer[mailServerIndex].getServerName() 
    << " , index = " << mailServerIndex <<endl;
    this->mailServerIndex++;
    return;
}

void LoadBalancingServer::printSearchServerStatus() {
    // Todo: you are suppose to finish this function
    // starts from here
    cout << "Search server status: Total server = " << SearchServer::serverNumber 
    << " Live server = " << SearchServer::liveServerNumber << endl;

    // ends here
}

void LoadBalancingServer::printMailServerStatus() {
    // Todo: you are suppose to finish this function
    // starts from here
    cout << "Mail server status: Total server = " << MailServer::serverNumber 
    << " Live server = " << MailServer::liveServerNumber << endl;
    // ends here
}