//
// Created by ws on 2021/3/2.
// Modified by jx on 2021/4/7.
//

#ifndef MAILSERVER_H
#define MAILSERVER_H

#include "IServer.h"
#include "Request.h"
#include <string>
#include <queue>

class MailServer: public IServer {
private:
    int requestCnt = 0;
    string serverName = "MAIL_SERVER";
    int currentLoad = 0;
    int maxLoad = 100;
    bool isLive = true;
    std::queue<Request> requestQueue;

public:
    MailServer(string name) {this->serverName = name; serverNumber++; liveServerNumber++;}
    void refuseToPush();
    void goodToWork();
    void pushJobQueue(Request req);
    Request handleJobQueue();
    Response process(Request req);
    void printInfo() const;
    string getServerName() const;
    static int serverNumber;
    static int liveServerNumber;
};


#endif
