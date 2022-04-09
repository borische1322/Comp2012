#ifndef CUSTOMER_H
#define CUSTOMER_H

/* ======================================
    TODO: Complete the class declaration of Customer
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/
#include "Person.h"

class Customer : public Person
{
    std::string gender;

    public:

    Customer(const std::string& pname, const std::string& pgender);

    std::string get_gender() const;

};
#endif