//
// Created by ws on 2021/3/2.
//
#include <iostream>
#include <string>

using namespace std;

#include "Request.h"

string Request::getRequestContent() const
{
    return this->requestContent;
}

int Request::getUserId() const { return this->userId; }

string Request::getUserName() const { return this->userName; }

Request::Request(int userId, string userName, string requestContent, RequestType type)
{
    this->userId = userId;
    this->userName = userName;
    this->requestContent = requestContent;
    this->requestType = type;
}

void Request::printInfo() const
{
    cout << "user id: " << this->getUserId() << ", user name: " << this->getUserName() << ", request: " << this->getRequestContent() << endl;
}