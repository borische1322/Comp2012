//
// Created by ws on 2021/3/6.
// Modified by jx on 2021/4/7.
//

#ifndef SEARCHSERVER_H
#define SEARCHSERVER_H

#include "IServer.h"
#include <string>
#include <iostream>
#include <queue>

class SearchServer: public IServer {
private:
    int requestCnt = 0;
    string serverName = "SEARCH_SERVER";
    int currentLoad = 0;
    int maxLoad = 100;
    bool isLive = true;
    std::queue<Request> requestQueue;

public:
    SearchServer(string name) {this->serverName = name; serverNumber++; liveServerNumber++;}
    void refuseToPush() {this->isLive = false; liveServerNumber--;}
    void goodToWork() {if(!this->isLive) {this->isLive = true; liveServerNumber++;}}
    void pushJobQueue(Request req);
    Request handleJobQueue();
    Response process(Request req);
    void printInfo() const;
    string getServerName() const;
    static int serverNumber;
    static int liveServerNumber;
};

#endif //SEARCHSERVER_H


