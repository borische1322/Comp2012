//
// Created by ws on 2021/3/6.
//

#ifndef SEARCHSERVER_H
#define SEARCHSERVER_H

#include "IServer.h"
#include <string>
#include <iostream>

using namespace std;

class SearchServer : public IServer
{
private:
    int requestCnt = 0;
    string serverName = "SEARCH_SERVER";

public:
    Response process(Request req);
    void printSummary() const;
    string getServerName() const;
    ~SearchServer();
};

#endif //SEARCHSERVER_H
