//
// Created by jx on 2021/4/11.
//

#include "LBServer.h"
#include "MailServer.h"
#include "SearchServer.h"
#include "Request.h"
#include "Response.h"
#include <iostream>
using namespace std;

int SearchServer::serverNumber = 0;
int SearchServer::liveServerNumber = 0;
int MailServer::serverNumber = 0;
int MailServer::liveServerNumber = 0;

int main()
{
    SearchServer ss1("ss1");
    SearchServer ss2("ss2");
    SearchServer ssSet[] = {ss1, ss2};
    LoadBalancingServer lbs("lbs1");

    lbs.registerSearchServer(2, ssSet);

    LoadBalancingServer::printSearchServerStatus();
    return 0;
}
