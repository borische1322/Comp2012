#include "WesternDish.h"
#include <iostream>
using namespace std;

// TODO: complete the constructor of WesternDish
WesternDish::WesternDish(const string& dname, const string& drare_level): Dish(dname), rare_level(drare_level){}

// TODO: complete WesternDish::get_rare_level
std::string WesternDish::get_rare_level() const{
    return rare_level;
}