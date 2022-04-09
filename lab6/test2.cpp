//
// Created by jx on 2021/4/7.
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
    Request r1(EMAIL, 10, 1);
    Request r2(SEARCH, 20, 2);
    Request r3(SEARCH, 30, 3);
    Request r4(SEARCH, 30, 4);
    Request r5(SEARCH, 80, 5);
    Request r6(SEARCH, 30, 6);
    Request r7(SEARCH, 30, 7);

    SearchServer ss1("ss1");
    SearchServer ss2("ss2");
    SearchServer ssSet[] = {ss1, ss2};
    LoadBalancingServer lbs("lbs1");

    lbs.registerSearchServer(2, ssSet);
    lbs.process(r1);
    lbs.process(r2);
    lbs.process(r3);
    lbs.process(r4);
    LoadBalancingServer::printSearchServerStatus();
    lbs.process(r5);
    LoadBalancingServer::printSearchServerStatus();
    lbs.process(r6);
    lbs.process(r7);

    cout<< "There is one search server down! Let's wait a second to assign tasks." << endl;
    // We should not use ss1 and ss2 here, you can test to see why.
    ssSet[0].process( ssSet[0].handleJobQueue() );
    ssSet[1].process( ssSet[1].handleJobQueue() );
    LoadBalancingServer::printSearchServerStatus();
    return 0;
}
