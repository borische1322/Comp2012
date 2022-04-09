//
// Created by ws on 2021/3/6.
//

#ifndef DefaultServer_H
#define DefaultServer_H

#include "IServer.h"
#include <string>
using namespace std;

class DefaultServer: public IServer {
private:
    int requestCnt = 0;
    string serverName = "DEFAULT_SERVER";
public:
    Response process(Request req);
    void printSummary() const;
    string getServerName() const {return this->serverName;};
};


#endif //
