//
// Created by ws on 2021/3/2.
//

#ifndef REQUEST_H
#define REQUEST_H

#include <string>
using namespace std;

enum RequestType {
    EMAIL = 0,
    SEARCH = 1,
    UNKNOWN = 404,
};

class Request {
private:
    int userId;
    string userName;
    string requestContent;
    RequestType requestType = EMAIL;

public:
    Request(int userId, string userName, string requestContent, RequestType type);
    int getUserId() const;
    string getUserName() const;
    string getRequestContent() const;
    void printInfo() const;
    RequestType getRequestType() const {return this->requestType;}
};

#endif //REQUEST_H
