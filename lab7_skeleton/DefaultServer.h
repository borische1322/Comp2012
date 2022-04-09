//
// Created by ws on 2021/3/6.
//

#ifndef DefaultServer_H
#define DefaultServer_H

#include "IServer.h"
#include <string>

class DefaultServer : public IServer
{
private:
    int requestCnt = 0;
    std::string serverName = "DEFAULT_SERVER";

public:
    Response process(Request req);
    void printSummary() const;
    std::string getServerName() const { return this->serverName; };
    ~DefaultServer();
};

#endif //

#include "block_loops.h"