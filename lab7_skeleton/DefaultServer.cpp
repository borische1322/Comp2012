//
// Created by ws on 2021/3/6.
//

#include "DefaultServer.h"

#include <iostream>
#include <string>

using namespace std;

void DefaultServer::printSummary() const
{
    // =============== TODO Start ===============

    cout << this->getServerName() << ": " << this->requestCnt << " unknown requests." << endl;

    // =============== TODO End   ===============
}

Response DefaultServer::process(Request req)
{
    cout << this->getServerName() << " is processing a request from " << req.getUserName() << ". Return the 404 page." << endl;
    this->requestCnt += 1;
    Response res = Response(req.getUserId(), req.getUserName(), "404 Page", 1);
    return res;
}

DefaultServer::~DefaultServer() { std::cout << "Default server is destructed." << std::endl;  }