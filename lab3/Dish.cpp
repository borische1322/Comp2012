#include "Dish.h"
#include <iostream>
using namespace std;

Dish::Dish(const string& dname): name(dname) {}

string Dish::get_name() const {
    return name;
}
