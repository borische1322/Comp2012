//
// Created by ws on 2021/3/2.
//

#ifndef MAILSERVER_H
#define MAILSERVER_H

#include "IServer.h"
#include <string>
using namespace std;

class MailServer: public IServer {
private:
    int requestCnt = 0;
    string serverName = "MAIL_SERVER";
public:
    Response process(Request req);
    void printSummary() const;
    string getServerName() const;
};


#endif
