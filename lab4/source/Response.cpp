//
// Created by ws on 2021/3/2.
//
#include<iostream>
#include<string>
using namespace std;

#include "Response.h"

string Response::getResponseContent() const {return this->responseContent;}

int Response::getUserId() const {return this->userId;}

string Response::getUserName() const {return this->userName;}

int Response::getStatus() const {return this->status;}

Response::Response(int userId, string userName, string responseContent, int status) {
    this->userId = userId;
    this->userName  = userName;
    this->responseContent = responseContent;
    this->status = status;
}

void Response::printInfo() const {
    cout << "user id: " << this->getUserId() << ", user name: " << this->getUserName() << ", response status: " << this->getStatus() << ", content: " << this->getResponseContent() << endl;
}