#include <iostream>
#include "Customer_order_ChineseDish.h"
using namespace std;

// TODO: complete the constructor of Customer_order_ChineseDish
Customer_order_ChineseDish::Customer_order_ChineseDish(const string& pname, const string& pgender, const string& pmain_food, const string& dname, const int dhot_level): Customer(pname, pgender), main_food(pmain_food), order(ChineseDish(dname, dhot_level)){
}
void Customer_order_ChineseDish::print_main_food() const {
    cout << get_name() << " ordered main food: " << main_food << "." << endl;
}

void Customer_order_ChineseDish::print_dish_info() const {
    cout << get_name() << " ordered dish: " << order.get_name() << ", whose hot_level is " << order.get_hot_level() << "." << endl;
}