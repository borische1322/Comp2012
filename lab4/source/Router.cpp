//
// Created by ws on 2021/3/8.
//

#include "Router.h"

IServer * Router::getServer(RequestType requestType) {
    // An elegant (high-level) way to implement router is using "observer patten".
    // refer to <a href="https://en.wikipedia.org/wiki/Observer_pattern">Observer Pattern(Wiki)</a>
    // But, for simplicity, just use "case-switch".
    switch (requestType) {
        // =============== TODO Start ===============
        case EMAIL: return this->mailServer;

        case SEARCH: return this->searchServer;
       // =============== TODO End   ===============

        default :
            return this->defaultServer;
    }
}

Response Router::doRequest(Request req) {
    IServer *server = this->getServer(req.getRequestType()); // dynamic binding here
    Response response = server->process(req);
    server->printSummary();
    return response;
}