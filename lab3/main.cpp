#include <iostream>
#include "Waiter.h"
#include "Customer.h"
#include "Customer_order_ChineseDish.h"
#include "Customer_order_WesternDish.h"
using namespace std;

/* ======================================
    TODO: print the customer coming message according to the expected output
    HINT: remember to use subsitution policy
   ======================================*/
void customer_coming(Customer customer) {
    cout << "A " << customer.get_gender() << " customer " << customer.get_name() << " comes."<< endl;
}

int main()
{
    Waiter waiter1{"Simon"};
    Waiter waiter2{"Mary"};

    Customer_order_ChineseDish customer1{"Alice", "female", "rice", "Spicy diced chicken with peanuts", 3};
    Customer_order_WesternDish customer2{"Bob", "male", "Fish-and-chips", "Well"};
    Customer_order_ChineseDish customer3{"Jack", "male", "noodles", "Mapo Tofu", 5};
    Customer_order_WesternDish customer4{"Lucy", "female", "Filet", "Medium"};
    
    customer_coming(customer1);
    customer_coming(customer2);
    customer_coming(customer3);
    customer_coming(customer4);

    waiter1.responsible_for(&customer1);
    waiter1.responsible_for(&customer2);
    waiter2.responsible_for(&customer3);
    waiter2.responsible_for(&customer4);

    waiter1.print_customer_name_list();
    customer1.print_main_food();
    customer1.print_dish_info();
    customer2.print_dish_info();

    waiter2.print_customer_name_list();
    customer3.print_main_food();
    customer3.print_dish_info();
    customer4.print_dish_info();

    return 0;
}


