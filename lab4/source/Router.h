//
// Created by ws on 2021/3/8.
//

#ifndef LAB_ROUTER_H
#define LAB_ROUTER_H

#include "Response.h"
#include "Request.h"
#include "MailServer.h"
#include "DefaultServer.h"
#include "SearchServer.h"
#include "IServer.h"

class Router {
private:
    IServer *mailServer = new MailServer();
    IServer *searchServer = new SearchServer();
    IServer *defaultServer = new DefaultServer();
public:
    IServer *getServer(RequestType requestType);
    Response doRequest(Request req);
};


#endif //LAB_ROUTER_H
