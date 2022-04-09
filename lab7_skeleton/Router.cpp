//
// Created by ws on 2021/3/8.
//

#include "Router.h"

#include <algorithm>
#include <map>

#include "block_loops.h"

using namespace std;

void Router::registerServer(RequestType requestType, IServer *serverInstance)
{
    // TODO: Modify the serverRegistry to associate the requestType with the serverInstance
    serverRegistry[requestType] = serverInstance;

}

IServer *Router::getServer(RequestType requestType)
{
    // TODO: Lookup the serverRegistry to get the corresponding server instance for the given requestType
    return serverRegistry[requestType];

}

Response Router::processRequest(const Request &req)
{
    IServer *server = this->getServer(req.getRequestType());
    Response response = server->process(req);
    server->printSummary();
    return response;
}

Router::~Router()
{
    // TODO: Release all the servers in serverRegistry by using delete statement
    // You are NOT ALLOWED to use a for loop or a while loop
    // You may leverage the for_each function (http://www.cplusplus.com/reference/algorithm/for_each/) to complete this task
    // Hint: It can be done using a single line of code
    // Hint2: The type of the elements in a map<A,B> is pair<A,B>
    for_each(serverRegistry.begin(), serverRegistry.end(), [](pair<RequestType, IServer*> x){delete x.second;});

}