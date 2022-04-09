#ifndef CUSTOMER_ORDER_CHINESEDISH_H
#define CUSTOMER_ORDER_CHINESEDISH_H

/* ======================================
    TODO: Complete the class declaration of Customer_order_ChineseDish
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/
#include "Customer.h"
#include "ChineseDish.h"

class Customer_order_ChineseDish: public Customer
{
    std::string main_food;
    ChineseDish order;

    public:
    Customer_order_ChineseDish(const std::string& pname, const std::string& pgender, const std::string& pmain_food, const std::string& dname, const int dhot_level);
    void print_main_food() const;
    void print_dish_info() const;
};

#endif