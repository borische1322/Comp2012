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
    Request r1(SEARCH, 10, 1);
    Request r2(EMAIL, 20, 2);
    Request r3(EMAIL, 30, 3);
    Request r4(EMAIL, 30, 4);
    Request r5(EMAIL, 80, 5);
    Request r6(EMAIL, 30, 6);
    Request r7(EMAIL, 30, 7);

    MailServer ms1("ms1");
    MailServer ms2("ms2");
    MailServer msSet[] = {ms1, ms2};
    LoadBalancingServer lbs("lbs1");

    lbs.registerMailServer(2, msSet);
    LoadBalancingServer::printMailServerStatus();
    
    lbs.process(r1);
    lbs.process(r2);
    lbs.process(r3);
    lbs.process(r4);
    
    LoadBalancingServer::printMailServerStatus();
    lbs.process(r5);
    LoadBalancingServer::printMailServerStatus();
    lbs.process(r6);
    lbs.process(r7);

    cout<< "There is one mail server down! Let's wait a second to assign tasks." << endl;
    msSet[0].process( msSet[0].handleJobQueue() );
    msSet[1].process( msSet[1].handleJobQueue() );
    LoadBalancingServer::printMailServerStatus();
    return 0;
}
