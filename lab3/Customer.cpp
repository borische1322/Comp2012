#include <iostream>
#include "Customer.h"
using namespace std;

// TODO: complete the constructor of Customer
Customer::Customer(const string& pname, const string& pgender): Person(pname), gender(pgender) {}

// TODO: complete Customer::get_gender
string Customer::get_gender() const {
    return gender;
}