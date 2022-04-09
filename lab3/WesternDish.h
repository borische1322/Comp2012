#ifndef WESTERNDISH_H
#define WESTERNDISH_H

/* ======================================
    TODO: Complete the class declaration of WesternDish
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/

#include"Dish.h"

class WesternDish: public Dish{
    std::string rare_level;

    public:
    WesternDish(const std::string& dname, const std::string& drare_level);
    std::string get_rare_level() const;
};
#endif