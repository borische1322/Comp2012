//
// Created by ws on 2021/3/2.
//

#ifndef REQUEST_H
#define REQUEST_H

#include <string>

enum RequestType
{
    EMAIL = 0,
    SEARCH = 1,
    UNKNOWN = -1,
};

class Request
{
private:
    int userId;
    std::string userName;
    std::string requestContent;
    RequestType requestType = EMAIL;

public:
    Request(int userId, std::string userName, std::string requestContent, RequestType type);
    int getUserId() const;
    std::string getUserName() const;
    std::string getRequestContent() const;
    void printInfo() const;
    RequestType getRequestType() const { return this->requestType; }
};

#endif //REQUEST_H
