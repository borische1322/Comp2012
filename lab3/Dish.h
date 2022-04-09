#ifndef DISH_H
#define DISH_H

#include <string>

class Dish {
private:
    std::string name;
public:
    Dish(const std::string& dname);
    std::string get_name() const;
};

#endif