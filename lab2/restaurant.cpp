#include "restaurant.h"

#include <iostream>
#include <iomanip>
using namespace std;

/* ===================================================
    TODO: Complete the type conversion constructor.
          Here we assume to allocate same storage of size *n_storage* for fishes, potatoes and dishes.
          Try to add only one extra line of code!
    HINT: Reuse the general constuctor we define below.
   =================================================== */ 
Restaurant::Restaurant(int n_storage):Restaurant(n_storage, n_storage, n_storage)
{ 
    
    // Finish constructing with printing.
    cout << "By using the conversion constructor!" << endl;
}


/* ===================================================
    TODO: Complete the general constructor
          numFishes, numPotatoes, numDishes should be initialized to be 0
          maxNumFishes, maxNumPotatoes, maxNumDishes should be initialized to their assigned values
   =================================================== */ 
Restaurant::Restaurant(int n_Fishes, int n_Potatoes, int n_Dishes)
{
    numFishes = 0;
    numPotatoes = 0;
    numDishes = 0;

    maxNumDishes = n_Dishes;
    maxNumFishes = n_Fishes;
    maxNumPotatoes = n_Potatoes;

    // TODO: Allocate memory for fishStorage, potatoStorage and dishStorage here.
    fishStorage = new Fish* [n_Fishes];
    for (int i = 0; i < n_Fishes; ++i){
        fishStorage[i] = nullptr;
    }
    potatoStorage = new Potato* [n_Potatoes];
    for (int i = 0; i < n_Potatoes; ++i){
        potatoStorage[i] = nullptr;
    }
    dishStorage = new Dish* [n_Dishes];
    for (int i = 0; i < n_Dishes; ++i){
        dishStorage[i] = nullptr;
    }
  
    // Finish constructing with printing.
    cout << "Restaurant is Constructed!" << endl;
}


/* ===================================================
    TODO: Complete the copy constructor
          Deep copy all data members of another restaurant
   =================================================== */ 
Restaurant::Restaurant(const Restaurant &other)
{
    numFishes = other.numFishes;
    numPotatoes = other.numPotatoes;
    numDishes = other.numDishes;

    maxNumDishes = other.maxNumDishes;
    maxNumFishes = other.maxNumFishes;
    maxNumPotatoes = other.maxNumPotatoes;

    // TODO: Clone the fish storage.
    fishStorage = new Fish* [other.maxNumFishes];
    for (int i = 0; i < other.numFishes; ++i){
        fishStorage[i] = new Fish(*(other.fishStorage[i]));
        
    }

    // TODO: Clone the potato storage.
	potatoStorage = new Potato* [other.maxNumPotatoes];
    for (int i = 0; i < other.numPotatoes; ++i){
        potatoStorage[i] = new Potato(*(other.potatoStorage[i]));
    }

    // TODO: Clone the dish storage.
    dishStorage = new Dish* [other.maxNumDishes];
    for (int i = 0; i < other.numDishes; ++i){
        dishStorage[i] = new Dish(*(other.dishStorage[i]));
    }

    // Finish copying with printing.
    cout << "Restaurant is Copied!" << endl;
}


/* ===================================================
    TODO: Complete the destructor
   =================================================== */ 
Restaurant::~Restaurant()
{
    // TODO: Destruct the fish storage.
    for (int i = 0; i < numFishes; ++i){
        delete fishStorage[i];
    }

    delete [] fishStorage;

    fishStorage = nullptr;
    
    // TODO: Destruct the potato storage.
    for (int i = 0; i < numPotatoes; ++i){
        delete potatoStorage[i];
    }

    delete [] potatoStorage;

    potatoStorage = nullptr;
    
    // TODO: Destruct the dish storage.
    for (int i = 0; i < numDishes; ++i){
        delete dishStorage[i];
    }

    delete [] dishStorage;

    dishStorage = nullptr;
    
    // Finish destructing with printing.
    cout << "Restaurant is Destructed." << endl;
}


void Restaurant::storeFish()
{
    if (numFishes >= maxNumFishes)
    {
        cout << "Error: Fish storage is full, store failed." << endl;
    }
    else
    {
        // TODO: Store a unit of fish by allocating a Fish object.
        fishStorage[numFishes++] = new Fish;
    }
}


void Restaurant::storePotato()
{
    if (numPotatoes >= maxNumPotatoes)
    {
        cout << "Error: Potato storage is full, store failed." << endl;
    }
    else
    {
        // TODO: store a unit of potato by allocating a Potato object.
        potatoStorage[numPotatoes++] = new Potato;
    }
}


void Restaurant::cookDish()
{
    if (numDishes >= maxNumDishes)
    {
        cout << "Error: Dish storage is full, cook failed." << endl;
    }
    else if (numPotatoes < 1 || numFishes < 1)
    {
        cout << "Error: No enough materials for cooking a Dish" << endl;
    }
    else
    {
        /* ===================================================
            TODO: Cook a unit of dish by using fish and potato objects.
            Since the production of fish-and-chips requires both fishes and potatoes,
            it will consume one unit of fish and one unit of potato at the top of both storages for each dish.
            The ownership of the top fish and top potato is then transferred to the dish object,
            which means the Fish object and the Potato object are now pointed by the new Dish object instead.
           =================================================== */ 
           numFishes -= 1;
           numPotatoes -= 1;

           dishStorage[numDishes] = new Dish(fishStorage[numFishes], potatoStorage[numPotatoes]);

           numDishes++;
           fishStorage[numFishes] = nullptr;
           potatoStorage[numPotatoes] = nullptr;


    }
}

void Restaurant::serveDish()
{
	// TODO: Serve all Dishs by deleting each of them in the dishStorage
    while (numDishes){
    delete dishStorage[numDishes - 1];
    numDishes--;
    dishStorage[numDishes] = nullptr;
    }
}


void Restaurant::print() const
{
    cout << "----------------------" << endl;
    cout << "| Restaurant Summary |" << endl;
    cout << "----------------------" << endl;
    cout << "|" << setw(8) << "Fish"   << setw(7) << "(" << numFishes   << "/" << maxNumFishes   << ") |" << endl;
    cout << "|" << setw(8) << "Potato" << setw(7) << "(" << numPotatoes << "/" << maxNumPotatoes << ") |" << endl;
    cout << "|" << setw(8) << "Dish"   << setw(7) << "(" << numDishes   << "/" << maxNumDishes   << ") |" << endl;
    cout << "----------------------" << endl;
}
