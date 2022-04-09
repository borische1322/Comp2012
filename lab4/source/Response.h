//
// Created by ws on 2021/3/2.
//

#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
using namespace std;

class Response {
private:
    int userId;
    string userName;
    string responseContent;
    int status;

public:
    Response(int userId, string userName, string responseContent, int status);
    int getUserId() const;
    string getUserName() const;
    string getResponseContent() const;
    int getStatus() const;
    void printInfo() const;
};

#endif
