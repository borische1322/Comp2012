#include <iostream>
#include "Customer_order_WesternDish.h"
using namespace std;

// TODO: complete the constructor of Customer_order_WesternDish
Customer_order_WesternDish::Customer_order_WesternDish(const string& pname, const string& pgender, const string& dname, const string& drare_level): Customer(pname, pgender), order(WesternDish(dname, drare_level)){}

void Customer_order_WesternDish::print_dish_info() const {
    cout << get_name() << " ordered dish: " << order.get_name() << ", whose rare_level is " << order.get_rare_level() << "." << endl;
}