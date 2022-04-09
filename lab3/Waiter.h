#ifndef WAITER_H
#define WAITER_H

const int MAX_NUM_OF_CUSTOMERS = 5;

/* ======================================
    TODO: Complete the class declaration of Waiter
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/
#include"Person.h"
#include"Customer.h"

class Waiter: public Person{
    int num_of_customer;
    const Customer* customer_list[MAX_NUM_OF_CUSTOMERS];

    public:
    Waiter(const std::string& pname);

    void responsible_for(const Customer * customer);

    void print_customer_name_list() const;
};
#endif