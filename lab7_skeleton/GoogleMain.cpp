#include <iostream>
#include <algorithm>
#include <vector>

#include "Request.h"
#include "Response.h"
#include "Router.h"

#include "MailServer.h"
#include "SearchServer.h"
#include "DefaultServer.h"

using namespace std;

int main()
{
    cout << "Starting the main server\n";

    const int TIM_ID = 123;
    const int TIM_DAD_ID = 321;
    const int HACKER_ID = 224;
    
    vector<Request> reqs{
        // tim and his dad
        Request(TIM_ID, "Tim", "Dear Dad, I want a new iPhone.", EMAIL),
        Request(TIM_DAD_ID, "Tim_Dad", "Tim, I have no money.", EMAIL),
        Request(TIM_ID, "Tim", "Dear Dad, I see ...", EMAIL),
        Request(TIM_ID, "Tim", "How to make money?", SEARCH),
        Request(TIM_ID, "Tim", "How to find a job?", SEARCH),

        // a hacker
        Request(HACKER_ID, "Hacker", "Dear Tim, join us to get rich overnight.", UNKNOWN),
        Request(HACKER_ID, "Hacker", "Dear Tim, join us to get rich overnight.", EMAIL),
        Request(HACKER_ID, "Hacker", "Dear Tim, please click this link to find a job.", EMAIL),

        // tim
        Request(TIM_ID, "Tim", "Dear HR, I want a job.", EMAIL),
        Request(TIM_ID, "Tim", "Dear Dad, I have a job and start to make money by myself.", EMAIL),
    };

    Router router;
    router.registerServer(RequestType::EMAIL, new MailServer());
    router.registerServer(RequestType::SEARCH, new SearchServer());
    router.registerServer(RequestType::UNKNOWN, new DefaultServer());

    // TODO: Iterate over all the elements in reqs; feed each of them to router.processRequest()
    // You are NOT ALLOWED to use a for/while loop
    // You must use the for_each function (http://www.cplusplus.com/reference/algorithm/for_each/) to complete this task
    // Hint: It can be done using a single line of code
    for_each(reqs.begin(), reqs.end(), [&](Request x){router.processRequest(x);});
    
    
    cout << "Stopping the main server\n";
    return 0;
}
