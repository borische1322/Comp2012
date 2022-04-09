//
// Created by ws on 2021/3/2.
// Modified by jx on 2021/4/7.
//

#include<iostream>
#include <string>

using namespace std;

#include "Request.h"

Request::Request(RequestType type, int requestLoad, int requestID) {
    this->requestType = type;
    this->requestLoad = requestLoad;
    this->requestID = requestID;
}

Request::Request(const Request& other) {
    this->requestType = other.requestType;
    this->requestLoad = other.requestLoad;
    this->requestID = other.requestID;
}
