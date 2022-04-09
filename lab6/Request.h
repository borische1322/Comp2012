//
// Created by ws on 2021/3/2.
// Modified by jx on 2021/4/7.
//

#ifndef REQUEST_H
#define REQUEST_H

#include <string>

enum RequestType {
    EMAIL = 0,
    SEARCH = 1,
    UNKNOWN = 404,
};

class Request {
    friend class SearchServer;
    friend class MailServer;
private:
    RequestType requestType = EMAIL;
    int requestLoad = 1;
    int requestID = 1;
    int getRequestLoad() const {return this->requestLoad;}

public:
    Request(RequestType type, int requestLoad, int requestID);
    Request(const Request& other);
    int getRequestId() const {return requestID;}
    RequestType getRequestType() const {return requestType;}
};

#endif //REQUEST_H
