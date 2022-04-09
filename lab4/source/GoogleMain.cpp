//
// Created by ws on 2021/3/2.
//

#include <iostream>
#include "Request.h"
#include "Response.h"
#include "Router.h"

using namespace std;


int main() {
    cout << "[INFO] Google main server is running!\n";

    int TIM_ID = 123;
    int TIM_DAD_ID = 321;
    int HACKER_ID = 224;
    Request *reqs = new Request[10]{
            // tim and his dad
            Request(TIM_ID, "Tim", "Dear Dad, i want a new iPhone.", EMAIL),
            Request(TIM_DAD_ID, "Tim_Dad", "Tim, i have no money.", EMAIL),
            Request(TIM_ID, "Tim", "Dear Dad, i see ...", EMAIL),
            Request(TIM_ID, "Tim", "how to make money?", SEARCH),
            Request(TIM_ID, "Tim", "how to find a job?", SEARCH),

            // a hacker
            Request(HACKER_ID, "Hacker", "Dear Tim, join us to get rich overnight.", UNKNOWN),
            Request(HACKER_ID, "Hacker", "Dear Tim, join us to get rich overnight.", EMAIL),
            Request(HACKER_ID, "Hacker", "Dear Tim, please click this link to find a job.", EMAIL),

            // tim
            Request(TIM_ID, "Tim", "Dear HR, i want a job.", EMAIL),
            Request(TIM_ID, "Tim", "Dear Dad, i have a job and start to make money by myself.", EMAIL),
    };

    Router *router = new Router();
    for (int i = 0; i < 10; i += 1) {
        Response response = router->doRequest(reqs[i]);
    }

    cout << "[INFO] Google main server stopped!\n";
    return 0;
}


