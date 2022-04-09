//
// Created by ws on 2021/3/8.
//

#ifndef LAB_ROUTER_H
#define LAB_ROUTER_H

#include<map>

#include "Response.h"
#include "Request.h"
#include "IServer.h"

class Router
{
private:
    std::map<RequestType, IServer*> serverRegistry;

public:
    IServer* getServer(RequestType requestType);
    void registerServer(RequestType reqType, IServer* server);
    Response processRequest(const Request& req);
    ~Router();
};

#endif //LAB_ROUTER_H
