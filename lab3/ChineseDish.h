#ifndef CHINESEDISH_H
#define CHINESEDISH_H

/* ======================================
    TODO: Complete the class declaration of ChineseDish
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/

#include"Dish.h"
class ChineseDish: public Dish{
    int hot_level;

    public:
    
    ChineseDish(const std::string& dname, const int dhot_level);

    int get_hot_level() const;
};

#endif