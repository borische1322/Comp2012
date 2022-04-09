#include "cell.h"
#include <iostream>
using namespace std;
//do NOT include anything else, write your code below

Cell::Cell():things(nullptr), thingCount(0){};

Cell::~Cell(){
    delete [] things;
}

bool Cell::addThing(ThingType type, int quantity){
    if (quantity < 1){ // check if quantity is more than 0
        return false;
    }

    Thing* temp_thing = new Thing [thingCount + quantity]; // to create a new dynamic array 

    if (things != nullptr){ // check if things is empty or not
        for (int i = 0; i < thingCount; ++i){ // copy things to temp_thing
            temp_thing[i] = things[i];
        }
        delete [] things; // delete things
    }

    for (int j = 0; j < quantity; ++j){ // add the new thing to temp_thing
        Thing objthing(type);
        temp_thing[thingCount + j] = objthing;
    }

    thingCount += quantity;
    things = temp_thing; // point ptr thingsd to the new array

    return true;
}

int Cell::getThingCount(ThingType type) const{
    int count_type = 0;
    if (thingCount == 0) {
        return count_type;
    }
    for (int i = 0; i < thingCount; ++i){
        if (things[i].getType() == type){
            count_type++;
        }
    }

    return count_type;
}

int Cell::getThingCount() const{
    return thingCount;
}

void Cell::removeEverything(){
    thingCount = 0;
    delete [] things;
    things = nullptr;
}

const Thing& Cell::getThing(int index) const{ // what about if things == nullptr??
    return things[index];
}

bool Cell::hasType(ThingType type) const{
    if (getThingCount(type)){
        return true;
    } else {
        return false;
    }

}

bool Cell::hasWeapons() const{
    if (getThingCount(MACE) || getThingCount(DAGGER) || getThingCount(SWORD)){
        return true;
    } else {
        return false;
    }
}

bool Cell::hasMonsters() const{
    if (getThingCount(SKELETON) || getThingCount(VAMPIRE) || getThingCount(DRAGON)){
        return true;
    } else {
        return false;
    }
}

int Cell::getThingTypeCount() const{
    int type_count = 0;

    if (getThingCount(MACE)){
        type_count++;
    }

    if (getThingCount(DAGGER)){
        type_count++;
    }

    if (getThingCount(SWORD)){
        type_count++;
    }

    if (getThingCount(SKELETON)){
        type_count++;
    }

    if (getThingCount(VAMPIRE)){
        type_count++;
    }

    if (getThingCount(DRAGON)){
        type_count++;
    }

    return type_count;
}

bool Cell::removeThing(ThingType type, int quantity){
    if (getThingCount(type) < quantity || quantity <= 0){
        return false;
    }

    if ((thingCount - quantity) == 0){
        thingCount -= quantity;
        delete [] things;
        things = nullptr;
        return true;
    }

    Thing* temp_thing = new Thing [thingCount - quantity];

    int pos = 0;
    int temp_quan = quantity;
    for (int i = 0; i < thingCount; ++i){
        if (things[i].getType() == type && temp_quan != 0){
            temp_quan--;
            pos += 1;
            continue;
        }
        temp_thing[i - pos] = things[i];
    }

    delete [] things;
    thingCount -= quantity;
    things = temp_thing;
    return true;
}

bool Cell::removeAnythingFromTheFront(int quantity){
    if (quantity <= 0 || thingCount < quantity){
        return false;
    } 

    if (thingCount == quantity){
        delete [] things;
        things = nullptr;
        thingCount = 0;
        return true;
    }

    Thing* temp_thing = new Thing [thingCount - quantity];

    for (int i = 0; i < thingCount - quantity; ++i){
        temp_thing[i].setType(things[i + quantity].getType());
    }

    delete [] things;
    things = temp_thing;
    thingCount -= quantity;
    return true;
}