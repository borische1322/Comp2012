#include "thing.h"
//do NOT include anything else, write your code below

Thing::Thing(ThingType type):type(type){};

void Thing::setType(ThingType type){
    this->type = type;
}

ThingType Thing::getType() const{
    return((type == MACE)? MACE :
                ((type == DAGGER)? DAGGER : 
                    ((type == SWORD)? SWORD :
                        ((type == SKELETON)? SKELETON :
                            ((type == VAMPIRE)? VAMPIRE : DRAGON)
                        )
                    )
                )
            );
}

bool Thing::isWeapon() const{
    if (type == MACE || type == DAGGER || type == SWORD){
        return true;
    } else {
        return false;
    }
}

bool Thing::isMonster() const{
    if (type == SKELETON || type == VAMPIRE || type == DRAGON){
        return true;
    } else {
        return false;
    }
}

char Thing::getSymbol() const{
    return((type == MACE)? 'm' :
                ((type == DAGGER)? 'd' : 
                    ((type == SWORD)? 's' :
                        ((type == SKELETON)? 'K' :
                            ((type == VAMPIRE)? 'V' : 'D')
                        )
                    )
                )
            );
}
