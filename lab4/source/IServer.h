//
// Created by ws on 2021/3/2.
//

#ifndef ISERVER_H
#define ISERVER_H

#include "Request.h"
#include "Response.h"

#include <string>

using namespace std;

class IServer {
public:
    virtual Response process(Request req) = 0; // process the request
    virtual void printSummary() const = 0; // print summary info
    virtual string getServerName() const = 0;  // report its name, used in other virtual functions
};


#endif
