//
// Created by ws on 2021/3/6.
//

#include "SearchServer.h"

#include <iostream>
#include <string>

using namespace std;

string SearchServer::getServerName() const {return this->serverName;}

void SearchServer::printSummary() const {
    cout << this->getServerName() << ": " << this->requestCnt << " requests." << endl;
}

Response SearchServer::process(Request req) {

    // =============== TODO Start ===============
    cout << this->getServerName() << " is processing a search request from " << req.getUserName() << ", keyword: " << req.getRequestContent() << endl;
    this->requestCnt += 1;

    // =============== TODO End  ===============

    Response res = Response(req.getUserId(), req.getUserName(), this->getServerName(), 0);
    return res;
}