#ifndef CUSTOMER_ORDER_WESTERNDISH_H
#define CUSTOMER_ORDER_WESTERNDISH_H

/* ======================================
    TODO: Complete the class declaration of Customer_order_WesternDish
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/
#include "Customer.h"
#include "WesternDish.h"

class Customer_order_WesternDish: public Customer{
    WesternDish order;

    public:
    Customer_order_WesternDish(const std::string& pname, const std::string& pgender, const std::string& dname, const std::string& drare_level);
    void print_dish_info() const;
};
#endif