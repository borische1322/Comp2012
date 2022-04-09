#include "ChineseDish.h"
#include <iostream>
using namespace std;

// TODO: complete the constructor of ChineseDish
ChineseDish::ChineseDish(const string& dname, const int dhot_level): Dish(dname), hot_level(dhot_level){}

// TODO: complete ChineseDish::get_hot_level
int ChineseDish::get_hot_level() const {
    return hot_level;
}