#include <iostream>
#include "Waiter.h"
using namespace std;

// TODO: complete the constructor of Waiter
Waiter::Waiter(const string& pname): Person(pname), num_of_customer(0){
}

// TODO: complete Waiter::responsible_for
void Waiter::responsible_for(const Customer * customer) {
    if (num_of_customer >= MAX_NUM_OF_CUSTOMERS){
        cout << "Reach the maximum number of customer." << endl;
        return;
    }
    customer_list[num_of_customer++] = customer;
    cout << "Waiter " << get_name() << " is responsible for customer " << customer->get_name() << "." << endl;
}

void Waiter::print_customer_name_list() const {
    cout << "Waiter " << get_name() << "'s customer:" << endl;
    for (int i = 0; i < num_of_customer; i++) {
        const Customer * p = customer_list[i];
        cout << "Customer " << i << ": " << p->get_name() << ", gender: " << p->get_gender() << endl;
    }
}
