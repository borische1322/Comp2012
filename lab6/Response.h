//
// Created by ws on 2021/3/2.
// Modified by jx on 2021/4/7.
//

#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>

class Response {
private:
    int respondID = 1;

public:
    Response();
    Response(int respondID) {this->respondID = respondID;};
};

#endif
