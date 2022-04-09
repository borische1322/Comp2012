//
// Created by ws on 2021/3/2.
//

#include "MailServer.h"
#include <iostream>
#include <string>

using namespace std;

string MailServer::getServerName() const { return this->serverName; }

void MailServer::printSummary() const
{
    cout << this->getServerName() << ": " << this->requestCnt << " requests." << endl;
}

Response MailServer::process(Request req)
{
    cout << this->getServerName() << " is processing an email from " << req.getUserName() << ", subject: "
         << req.getRequestContent() << endl;
    this->requestCnt += 1;

    Response res = Response(req.getUserId(), req.getUserName(), this->getServerName(), 0);
    return res;
}

MailServer::~MailServer() { std::cout << "Mail server is destructed." << std::endl;  }