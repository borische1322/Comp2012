//
// Created by jx on 2021/4/7.
//
#ifndef LBSERVER_H
#define LBSERVER_H

#include "SearchServer.h"
#include "MailServer.h"
#include <string>
#include <iostream>

class LoadBalancingServer: public IServer {
private:
    int requestCnt = 0;
    string serverName = "LOADBALANCING_SERVER";
    int searchServerNum = 0;
    int searchServerIndex = 0;
    int mailServerNum = 0;
    int mailServerIndex = 0;
    SearchServer* registeredSearchServer;
    MailServer* registeredMailServer;
public:
    LoadBalancingServer(string name) {this->serverName = name;}
    Response process(Request req);
    void assignMailTasks(Request req);
    void assignSearchTasks(Request req);
    void printInfo() const;
    string getServerName() const;
    void registerSearchServer(int number, SearchServer* servers) 
        {this->searchServerNum = number; this->registeredSearchServer=servers;}
    void registerMailServer(int number, MailServer* servers) 
        {this->mailServerNum = number; this->registeredMailServer=servers;}

    static void printSearchServerStatus();    
    static void printMailServerStatus();
};


#endif //LBSERVER_H
