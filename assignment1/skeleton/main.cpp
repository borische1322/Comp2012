#include <iostream>
#include "game.h"
#include "cell.h"
#include "thing.h"
using namespace std;

//this printing function is used to print information of a given Cell object in some of the test cases
void printCell(Cell& cell)
{
    cout << "printSymbol: "; 
    cell.printSymbol(); 
    cout << endl << "printThings: "; 
    cell.printThings();
}

//this printing function is used to print the cell array content at (x, y) of the given Game object in some of the test cases
void printGameCellArrayContent(Game& game, int x, int y)
{
    cout << "Cell array content at (" << x << ", " << y << "): "; 
    game.printThings(x, y);
}

int main()
{
    cout << "Hello! Who are you?" << endl;
    cout << "1. I am a programmer!" << endl;
    cout << "2. I am the HERO!" << endl;
    cout << "Your answer: ";
    int choice = 1;
    cin >> choice;
    cout << endl;
    if(choice == 2) //play the game
    {
        Game game(4, 5); //width = 4; height = 5

        game.addThing(0, 2, SWORD, 3);
        game.addThing(3, 3, DRAGON, 1);
        game.addThing(3, 3, DRAGON, 1);
        game.addThing(3, 1, VAMPIRE, 1);
        game.addThing(2, 0, MACE, 1);
        game.addThing(2, 0, DAGGER, 3);
        game.addThing(1, 3, DAGGER, 1);

        bool gameOver = false;
        while (!gameOver)
        {
            game.print();
            cout << "Hi Hero! What is your move? (w/a/s/d)" << endl;
            cout << "Your move: ";
            char move;
            cin >> move;
            cout << endl;
            switch (move)
            {
            case 'w':
            case 'a':
            case 's':
            case 'd':
                if (!game.moveHero(move))
                    cout << "We cannot move to there!" << endl;
                break;
            default:
                cout << "The hero has went crazy, aborting!" << endl;
                gameOver = true;
            }
            if (!game.isHeroAlive())
            {
                game.print();
                cout << "The Hero fought and died at (" << game.getHeroX() << "," << game.getHeroY() << ")... That place still has these monsters: ";
                game.printThings(game.getHeroX(), game.getHeroY());
                cout << "RIP. You tried! :(" << endl;
                gameOver = true;
            }
            else if (game.isAllMonstersGone())
            {
                game.print();
                cout << "GOOD JOB HERO! YOU HAVE SAVED THE WORLD!" << endl;
                gameOver = true;
            }
        }
    }
    else if(choice == 1) //test the test cases
    {
        cout << "OK! Let's test our program." << endl;

        int testCaseNumber = 1;
        cout << "Which test case? ";
        cin >> testCaseNumber;
        cout << endl;
        cout << "Running test case " << testCaseNumber << "..." << endl;
        cout << boolalpha << endl; //we want true/false instead of 1/0 in the output

        if(testCaseNumber == 1)
        {
            //description: test Thing::getType
            Thing t1;
            Thing t2(SKELETON);
            cout << t1.getType() << endl;
            cout << t2.getType() << endl;
        }
        else if(testCaseNumber == 2)
        {
            //description: test Thing::isWeapon/isMonster
            Thing t1(DRAGON);
            Thing t2(DAGGER);
            cout << t1.isWeapon() << " " << t1.isMonster() << endl; 
            cout << t2.isWeapon() << " " << t2.isMonster() << endl; 
        }
        else if(testCaseNumber == 3)
        {
            //description: test Thing::setType
            Thing t1;
            Thing t2;
            t1.setType(VAMPIRE);
            t2.setType(SWORD);
            cout << t1.getType() << endl;
            cout << t2.getType() << endl;
        }
        else if(testCaseNumber == 4)
        {
            //description: test Thing::getSymbol
            Thing t1;
            Thing t2;
            t1.setType(DRAGON);
            t2.setType(DAGGER);
            cout << t1.getSymbol() << endl;
            cout << t2.getSymbol() << endl;
        }
        else if(testCaseNumber == 5)
        {
            //description: test Cell::addThing
            Cell c;
            cout << "addThing: " << c.addThing(SKELETON, 1) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 6)
        {
            //description: test Cell::addThing, slightly higher quantity
            Cell c;
            cout << "addThing: " << c.addThing(SKELETON, 3) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 7)
        {
            //description: test Cell::addThing, mixed things
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 0) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, -1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 3) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 8)
        {
            //description: test Cell::removeThing
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 3) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 4) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 1) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 9)
        {
            //description: test Cell::removeThing, slightly higher quantity
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 3) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 3) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 4) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 2) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 10)
        {
            //description: test Cell::removeThing, slightly higher quantity and trickier
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 3) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 4) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 5) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 2) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 11)
        {
            //description: test Cell::removeAnythingFromTheFront
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 3) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 4) << endl;
            printCell(c);
            cout << "removeAnythingFromTheFront: " << c.removeAnythingFromTheFront(1) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 12)
        {
            //description: test Cell::removeAnythingFromTheFront, slightly higher quantity
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 3) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 4) << endl;
            printCell(c);
            cout << "removeAnythingFromTheFront: " << c.removeAnythingFromTheFront(4) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 13)
        {
            //description: test Cell::removeEverything
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 3) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 4) << endl;
            printCell(c);
            cout << "removeEverything..." << endl;
            c.removeEverything();
            printCell(c);
        }
        else if(testCaseNumber == 14)
        {
            //description: test Cell::getThing and Cell::getThingCount
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 3) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 4) << endl;
            cout << "c.getThingCount(): " << c.getThingCount() << endl;
            for(int i=0;i<c.getThingCount();i++)
                cout << i << ":" << c.getThing(i).getSymbol() << endl;
        }
        else if(testCaseNumber == 15)
        {
            //description: test Cell::getThingCount(ThingType)
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 3) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 9) << endl;
            cout << "getThingCount(VAMPIRE): " << c.getThingCount(VAMPIRE) << endl;
            cout << "getThingCount(DRAGON): " << c.getThingCount(DRAGON) << endl;
            cout << "getThingCount(SKELETON): " << c.getThingCount(SKELETON) << endl;
            cout << "getThingCount(MACE): " << c.getThingCount(MACE) << endl;
            cout << "getThingCount(DAGGER): " << c.getThingCount(DAGGER) << endl;
            cout << "getThingCount(SWORD): " << c.getThingCount(SWORD) << endl;
        }
        else if(testCaseNumber == 16)
        {
            //description: test Cell::hasWeapons/hasMonsters, for monsters
            Cell c;
            cout << c.hasWeapons() << " " << c.hasMonsters() << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << c.hasWeapons() << " " << c.hasMonsters() << endl;
        }
        else if(testCaseNumber == 17)
        {
            //description: test Cell::hasType, simple
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "hasType(SKELETON): " << c.hasType(SKELETON) << endl;
            cout << "hasType(VAMPIRE): " << c.hasType(VAMPIRE) << endl;
            cout << "hasType(DRAGON): " << c.hasType(DRAGON) << endl;
            cout << "hasType(MACE): " << c.hasType(MACE) << endl;
            cout << "hasType(DAGGER): " << c.hasType(DAGGER) << endl;
            cout << "hasType(SWORD): " << c.hasType(SWORD) << endl;
        }
        else if(testCaseNumber == 18)
        {
            //description: test Cell::hasType, less simple
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 2) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 1) << endl;
            cout << "hasType(SKELETON): " << c.hasType(SKELETON) << endl;
            cout << "hasType(VAMPIRE): " << c.hasType(VAMPIRE) << endl;
            cout << "hasType(DRAGON): " << c.hasType(DRAGON) << endl;
            cout << "hasType(MACE): " << c.hasType(MACE) << endl;
            cout << "hasType(DAGGER): " << c.hasType(DAGGER) << endl;
            cout << "hasType(SWORD): " << c.hasType(SWORD) << endl;
        }
        else if(testCaseNumber == 19)
        {
            //description: test Cell::getThingTypeCount, simple
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 2) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 1) << endl;
            cout << "getThingTypeCount: " << c.getThingTypeCount() << endl;
        }
        else if(testCaseNumber == 20)
        {
            //description: test Game constructor
            int width = 5;  //map width
            int height = 4; //map height
            cout << "An empty map:" << endl;
            Game game(width, height);
            game.print();
            cout << "Another empty map:" << endl;
            width = 5;
            height = 6;
            Game game2(width, height);
            game2.print();
        }
        else if(testCaseNumber == 21)
        {
            //description: Game copy constructor
            int width = 5;  //map width
            int height = 4; //map height
            Game game1(width, height);
            cout << "adding monster: " << game1.addThing(3, 2, VAMPIRE, 1) << endl;
            cout << "This is game1:" << endl;
            game1.print();
            printGameCellArrayContent(game1, 3, 2);
            printGameCellArrayContent(game1, 2, 3);
            cout << endl;
            cout << "Next we do the deep copy construction (copying game1 to game2)..." << endl;
            Game game2(game1);
            cout << endl;
            cout << "adding more monsters to game2: " << game2.addThing(3, 2, SKELETON, 1) << endl;
            cout << "adding more monsters to game2: " << game2.addThing(2, 3, DRAGON, 1) << endl;
            cout << "We print game2:" << endl;
            game2.print();
            printGameCellArrayContent(game2, 3, 2);
            printGameCellArrayContent(game2, 2, 3);
            cout << endl;
            cout << "Now we print game1 again, it shouldn't be affected:" << endl;
            game1.print();
            printGameCellArrayContent(game1, 3, 2);
            printGameCellArrayContent(game1, 2, 3);
        }
        else if(testCaseNumber == 22)
        {
            //description: test Game::addThing, simple, one edge case
            int width = 5;  //map width
            int height = 4; //map height
            Game game(width, height);
            cout << "adding monster: " << game.addThing(3, 2, VAMPIRE, 1) << endl;
            game.print();
            cout << "adding monster: " << game.addThing(3, 2, DRAGON, 2) << endl;
            cout << "adding monster: " << game.addThing(3, 2, VAMPIRE, 1) << endl;
            cout << "adding monster: " << game.addThing(3, 2, SKELETON, 3) << endl;
            game.print();
            cout << "adding monster: " << game.addThing(5, 3, SKELETON, 3) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
        }
        else if(testCaseNumber == 23)
        {
            //description: test Game::removeThing, simple, one edge case
            int width = 5;  //map width
            int height = 4; //map height
            Game game(width, height);
            cout << "adding monster: " << game.addThing(3, 2, VAMPIRE, 1) << endl;
            cout << "adding monster: " << game.addThing(3, 2, DRAGON, 2) << endl;
            cout << "adding monster: " << game.addThing(3, 2, VAMPIRE, 1) << endl;
            cout << "adding monster: " << game.addThing(3, 2, SKELETON, 3) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
            cout << "removing monster: " << game.removeThing(3, 2, VAMPIRE, 1) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
            cout << "removing monster: " << game.removeThing(3, 2, DRAGON, 2) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
            cout << "removing monster: " << game.removeThing(3, 2, VAMPIRE, 1) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
            cout << "removing monster: " << game.removeThing(3, 2, SKELETON, 3) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
            cout << "removing monster: " << game.removeThing(5, 3, SKELETON, 3) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
        }
        else if(testCaseNumber == 24)
        {
            //description: test Game::isAllMonstersGone, simple
            int width = 5;  //map width
            int height = 4; //map height
            Game game(width, height);
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "adding monster: " << game.addThing(3, 2, DRAGON, 2) << endl;
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
        }
        else if(testCaseNumber == 25)
        {
            //description: test Game::getMonsterCount, simple
            int width = 5;  //map width
            int height = 4; //map height
            Game game(width, height);
            cout << "getMonsterCount: " << game.getMonsterCount() << endl;
            cout << "adding monster: " << game.addThing(3, 2, DRAGON, 2) << endl;
            cout << "getMonsterCount: " << game.getMonsterCount() << endl;
        }
        else if(testCaseNumber == 26)
        {
            //description: test Game::getHeroX/getHeroY and Game::moveHero, simple
            int width = 5;  //map width
            int height = 4; //map height
            Game game(width, height);
            cout << "getHeroX: " << game.getHeroX() << endl;
            cout << "getHeroY: " << game.getHeroY() << endl;
            cout << "moveHero: " << game.moveHero('s') << endl;
            cout << "getHeroX: " << game.getHeroX() << endl;
            cout << "getHeroY: " << game.getHeroY() << endl;
            cout << "moveHero: " << game.moveHero('d') << endl;
            cout << "getHeroX: " << game.getHeroX() << endl;
            cout << "getHeroY: " << game.getHeroY() << endl;
        }
        else if(testCaseNumber == 27)
        {
            //description: test of moving hero to get weapons
            int width = 5;  //map width
            int height = 4; //map height
            Game game(width, height);
            game.addThing(2, 1, DAGGER, 1);
            game.addThing(2, 1, DAGGER, 1);
            game.addThing(3, 2, SKELETON, 1);
            game.addThing(3, 2, VAMPIRE, 3);
            game.addThing(3, 3, MACE, 1);
            game.addThing(3, 3, SWORD, 3);
            game.addThing(3, 3, DAGGER, 2);
            game.print();
            cout << "moveHero: " << game.moveHero('d') << endl;
            cout << "moveHero: " << game.moveHero('d') << endl;
            cout << "moveHero: " << game.moveHero('s') << endl; //get weapons
            game.print();
            cout << "moveHero: " << game.moveHero('s') << endl;
            cout << "moveHero: " << game.moveHero('s') << endl;
            cout << "moveHero: " << game.moveHero('d') << endl; //get weapons
            game.print();
            printGameCellArrayContent(game, 2, 1);
            printGameCellArrayContent(game, 1, 2);
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
            printGameCellArrayContent(game, 3, 3);
        }
        else if(testCaseNumber == 28)
        {
            //description: test of moving hero to get weapons, encounter monsters, and live
            int width = 5;  //map width
            int height = 4; //map height
            Game game(width, height);
            game.addThing(2, 1, DAGGER, 1);
            game.addThing(2, 1, DAGGER, 1);
            game.addThing(3, 2, SKELETON, 1);
            game.addThing(3, 2, VAMPIRE, 3);
            game.addThing(3, 3, MACE, 1);
            game.addThing(3, 3, SWORD, 3);
            game.addThing(3, 3, DAGGER, 2);
            game.print();
            cout << "moveHero: " << game.moveHero('d') << endl;
            cout << "moveHero: " << game.moveHero('d') << endl;
            cout << "moveHero: " << game.moveHero('s') << endl; //get weapons
            game.print();
            cout << "moveHero: " << game.moveHero('s') << endl;
            cout << "moveHero: " << game.moveHero('s') << endl;
            cout << "moveHero: " << game.moveHero('d') << endl; //get weapons
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            cout << "moveHero: " << game.moveHero('w') << endl; //encounter monsters
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            printGameCellArrayContent(game, 2, 1);
            printGameCellArrayContent(game, 1, 2);
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
            printGameCellArrayContent(game, 3, 3);
        }
        else if(testCaseNumber == 29)
        {
            //description: test of moving hero to get weapons, encounter monsters, and die
            int width = 2;  //map width
            int height = 2; //map height
            Game game(width, height);
            game.addThing(1, 0, DAGGER, 1);
            game.addThing(1, 0, MACE, 1);
            game.addThing(1, 0, SWORD, 0);
            game.addThing(1, 1, VAMPIRE, 0);
            game.addThing(1, 1, SKELETON, 1);
            game.addThing(1, 1, DRAGON, 1);
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            printGameCellArrayContent(game, 0, 0);
            printGameCellArrayContent(game, 1, 0);
            printGameCellArrayContent(game, 0, 1);
            printGameCellArrayContent(game, 1, 1);
            cout << "moveHero: " << game.moveHero('d') << endl; //get weapons
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            cout << "moveHero: " << game.moveHero('s') << endl; //encounter monsters (not enough appropriate weapons to kill them all)
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            printGameCellArrayContent(game, 0, 0);
            printGameCellArrayContent(game, 1, 0);
            printGameCellArrayContent(game, 0, 1);
            printGameCellArrayContent(game, 1, 1);
        }
        else if(testCaseNumber == 30)
        {
            //description: test of moving hero to get weapons, encounter slightly complicated array of monsters, and die (killed by 2nd vampire)
            int width = 2;  //map width
            int height = 2; //map height
            Game game(width, height);
            game.addThing(1, 0, DAGGER, 1);
            game.addThing(1, 0, MACE, 10);
            game.addThing(1, 0, SWORD, 10);
            game.addThing(1, 1, VAMPIRE, 1);
            game.addThing(1, 1, SKELETON, 1);
            game.addThing(1, 1, VAMPIRE, 1);
            game.addThing(1, 1, DRAGON, 1);
            game.addThing(1, 1, VAMPIRE, 1);
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            printGameCellArrayContent(game, 0, 0);
            printGameCellArrayContent(game, 1, 0);
            printGameCellArrayContent(game, 0, 1);
            printGameCellArrayContent(game, 1, 1);
            cout << "moveHero: " << game.moveHero('d') << endl; //get weapons
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            cout << "moveHero: " << game.moveHero('s') << endl; //encounter monsters (not enough appropriate weapons to kill them all)
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            printGameCellArrayContent(game, 0, 0);
            printGameCellArrayContent(game, 1, 0);
            printGameCellArrayContent(game, 0, 1);
            printGameCellArrayContent(game, 1, 1);
        }



        //THE FOLLOWING ARE HIDDEN TEST CASES
        else if(testCaseNumber == 31)
        {
            //description: thorough test of most Thing functions
            Thing t;
            t.setType(DRAGON);
            cout << t.getType() << " " << t.getSymbol() << " " << t.isMonster() << " " << t.isWeapon() << endl;
            t.setType(SKELETON);
            cout << t.getType() << " " << t.getSymbol() << " " << t.isMonster() << " " << t.isWeapon() << endl;
            t.setType(VAMPIRE);
            cout << t.getType() << " " << t.getSymbol() << " " << t.isMonster() << " " << t.isWeapon() << endl;
            t.setType(DAGGER);
            cout << t.getType() << " " << t.getSymbol() << " " << t.isMonster() << " " << t.isWeapon() << endl;
            t.setType(MACE);
            cout << t.getType() << " " << t.getSymbol() << " " << t.isMonster() << " " << t.isWeapon() << endl;
            t.setType(SWORD);
            cout << t.getType() << " " << t.getSymbol() << " " << t.isMonster() << " " << t.isWeapon() << endl;
        }
        else if(testCaseNumber == 32)
        {
            //description: test Cell::addThing, many mixed things
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 3) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 3) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 4) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 0) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, -10) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 33)
        {
            //description: test Cell::addThing, many many mixed things
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 10) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 20) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 30) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 30) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 10) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 1000) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, -10) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 34)
        {
            //description: test Cell::removeThing, cases for returning false
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 3) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 0) << endl;
            cout << "removeThing: " << c.removeThing(VAMPIRE, -1) << endl;
            cout << "removeThing: " << c.removeThing(VAMPIRE, 10) << endl;
            cout << "removeThing: " << c.removeThing(SKELETON, 1) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 35)
        {
            //description: test Cell::removeThing, complete removal
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 2) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 1) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(DRAGON, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(SKELETON, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(DRAGON, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 1) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 36)
        {
            //description: test Cell::removeThing, complete removal, another order
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 2) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 1) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(DRAGON, 2) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 2) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(SKELETON, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 1) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 37)
        {
            //description: test Cell::removeThing, complete removal, yet another order
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 2) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 1) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(SKELETON, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 1) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(DRAGON, 2) << endl;
            printCell(c);
            cout << "removeThing: " << c.removeThing(VAMPIRE, 1) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 38)
        {
            //description: test Cell::removeAnythingFromTheFront, trickier, complete removal
            Cell c;
            cout << "addThing: " << c.addThing(VAMPIRE, 1) << endl;
            cout << "addThing: " << c.addThing(DRAGON, 2) << endl;
            cout << "addThing: " << c.addThing(VAMPIRE, 3) << endl;
            cout << "addThing: " << c.addThing(SKELETON, 4) << endl;
            printCell(c);
            cout << "removeAnythingFromTheFront: " << c.removeAnythingFromTheFront(11) << endl;
            printCell(c);
            cout << "removeAnythingFromTheFront: " << c.removeAnythingFromTheFront(0) << endl;
            printCell(c);
            cout << "removeAnythingFromTheFront: " << c.removeAnythingFromTheFront(-1) << endl;
            printCell(c);
            cout << "removeAnythingFromTheFront: " << c.removeAnythingFromTheFront(5) << endl;
            printCell(c);
            cout << "removeAnythingFromTheFront: " << c.removeAnythingFromTheFront(5) << endl;
            printCell(c);
        }
        else if(testCaseNumber == 39)
        {
            //description: test Cell::removeEverything, when empty
            Cell c;
            printCell(c);
            cout << "removeEverything..." << endl;
            c.removeEverything();
            printCell(c);
        }
        else if(testCaseNumber == 40)
        {
            //description: test Cell::getThingCount(ThingType), for weapons
            Cell c;
            cout << "addThing: " << c.addThing(MACE, 1) << endl;
            cout << "addThing: " << c.addThing(DAGGER, 2) << endl;
            cout << "addThing: " << c.addThing(SWORD, 3) << endl;
            cout << "addThing: " << c.addThing(MACE, 9) << endl;
            cout << "getThingCount(VAMPIRE): " << c.getThingCount(VAMPIRE) << endl;
            cout << "getThingCount(DRAGON): " << c.getThingCount(DRAGON) << endl;
            cout << "getThingCount(SKELETON): " << c.getThingCount(SKELETON) << endl;
            cout << "getThingCount(MACE): " << c.getThingCount(MACE) << endl;
            cout << "getThingCount(DAGGER): " << c.getThingCount(DAGGER) << endl;
            cout << "getThingCount(SWORD): " << c.getThingCount(SWORD) << endl;
        }
        else if(testCaseNumber == 41)
        {
            //description: test Cell::hasWeapons/hasMonsters, for weapons
            Cell c;
            cout << c.hasWeapons() << " " << c.hasMonsters() << endl;
            cout << "addThing: " << c.addThing(DAGGER, 3) << endl;
            cout << c.hasWeapons() << " " << c.hasMonsters() << endl;
        }
        else if(testCaseNumber == 42)
        {
            //description: test Cell::hasType, for an empty cell
            Cell c;
            cout << "hasType(SKELETON): " << c.hasType(SKELETON) << endl;
            cout << "hasType(VAMPIRE): " << c.hasType(VAMPIRE) << endl;
            cout << "hasType(DRAGON): " << c.hasType(DRAGON) << endl;
            cout << "hasType(MACE): " << c.hasType(MACE) << endl;
            cout << "hasType(DAGGER): " << c.hasType(DAGGER) << endl;
            cout << "hasType(SWORD): " << c.hasType(SWORD) << endl;
        }
        else if(testCaseNumber == 43)
        {
            //description: test Cell::hasType, for weapons
            Cell c;
            cout << "addThing: " << c.addThing(MACE, 1) << endl;
            cout << "addThing: " << c.addThing(DAGGER, 2) << endl;
            cout << "addThing: " << c.addThing(MACE, 3) << endl;
            cout << "addThing: " << c.addThing(SWORD, 4) << endl;
            cout << "hasType(SKELETON): " << c.hasType(SKELETON) << endl;
            cout << "hasType(VAMPIRE): " << c.hasType(VAMPIRE) << endl;
            cout << "hasType(DRAGON): " << c.hasType(DRAGON) << endl;
            cout << "hasType(MACE): " << c.hasType(MACE) << endl;
            cout << "hasType(DAGGER): " << c.hasType(DAGGER) << endl;
            cout << "hasType(SWORD): " << c.hasType(SWORD) << endl;
        }
        else if(testCaseNumber == 44)
        {
            //description: test Cell::getThingTypeCount, for an empty cell
            Cell c;
            cout << "getThingTypeCount: " << c.getThingTypeCount() << endl;
        }
        else if(testCaseNumber == 45)
        {
            //description: test Cell::getThingTypeCount, for weapons
            Cell c;
            cout << "addThing: " << c.addThing(MACE, 1) << endl;
            cout << "addThing: " << c.addThing(DAGGER, 2) << endl;
            cout << "addThing: " << c.addThing(MACE, 3) << endl;
            cout << "addThing: " << c.addThing(SWORD, 4) << endl;
            cout << "getThingTypeCount: " << c.getThingTypeCount() << endl;
        }
        else if(testCaseNumber == 46)
        {
            //description: test Game constructor, bigger maps
            int width = 15;  //map width
            int height = 14; //map height
            cout << "An empty map:" << endl;
            Game game(width, height);
            game.print();
            cout << "Another empty map:" << endl;
            width = 15;
            height = 16;
            Game game2(width, height);
            game2.print();
        }
        else if(testCaseNumber == 47)
        {
            //description: Game copy constructor, empty square map
            int width = 3;  //map width
            int height = 3; //map height
            Game game1(width, height);
            cout << "This is game1:" << endl;
            game1.print();
            cout << endl;
            cout << "Next we do the deep copy construction (copying game1 to game2)..." << endl;
            Game game2(game1);
            cout << endl;
            cout << "adding more monsters to game2: " << game2.addThing(2, 2, SKELETON, 1) << endl;
            cout << "We print game2:" << endl;
            game2.print();
            printGameCellArrayContent(game2, 2, 2);
            cout << endl;
            cout << "Now we print game1 again, it shouldn't be affected:" << endl;
            game1.print();
            printGameCellArrayContent(game1, 2, 2);
        }
        else if(testCaseNumber == 48)
        {
            //description: Game copy constructor, bigger map
            int width = 15;  //map width
            int height = 14; //map height
            Game game1(width, height);
            cout << "adding monster: " << game1.addThing(13, 12, VAMPIRE, 1) << endl;
            cout << "This is game1:" << endl;
            game1.print();
            printGameCellArrayContent(game1, 13, 12);
            printGameCellArrayContent(game1, 12, 13);
            cout << endl;
            cout << "Next we do the deep copy construction (copying game1 to game2)..." << endl;
            Game game2(game1);
            cout << endl;
            cout << "adding more monsters to game2: " << game2.addThing(13, 12, SKELETON, 1) << endl;
            cout << "adding more monsters to game2: " << game2.addThing(12, 13, DRAGON, 1) << endl;
            cout << "We print game2:" << endl;
            game2.print();
            printGameCellArrayContent(game2, 13, 12);
            printGameCellArrayContent(game2, 12, 13);
            cout << endl;
            cout << "Now we print game1 again, it shouldn't be affected:" << endl;
            game1.print();
            printGameCellArrayContent(game1, 13, 12);
            printGameCellArrayContent(game1, 12, 13);
        }
        else if(testCaseNumber == 49)
        {
            //description: test Game::addThing, more edge cases
            int width = 5;  //map width
            int height = 4; //map height
            Game game(width, height);
            cout << "adding monster: " << game.addThing(3, 2, VAMPIRE, 1) << endl;
            game.print();
            cout << "adding monster: " << game.addThing(3, 2, DRAGON, 2) << endl;
            cout << "adding monster: " << game.addThing(3, 2, VAMPIRE, 1) << endl;
            cout << "adding monster: " << game.addThing(3, 2, SKELETON, 3) << endl;
            game.print();
            cout << "adding monster: " << game.addThing(5, 3, SKELETON, 3) << endl;
            cout << "adding monster: " << game.addThing(4, 4, SKELETON, 3) << endl;
            cout << "adding monster: " << game.addThing(0, -1, SKELETON, 3) << endl;
            cout << "adding monster: " << game.addThing(-1, 0, SKELETON, 3) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
        }
        else if(testCaseNumber == 50)
        {
            //description: test Game::removeThing, more edge cases
            int width = 5;  //map width
            int height = 4; //map height
            Game game(width, height);
            cout << "adding monster: " << game.addThing(3, 2, VAMPIRE, 1) << endl;
            cout << "adding monster: " << game.addThing(3, 2, DRAGON, 2) << endl;
            cout << "adding monster: " << game.addThing(3, 2, VAMPIRE, 1) << endl;
            cout << "adding monster: " << game.addThing(3, 2, SKELETON, 3) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
            cout << "removing monster: " << game.removeThing(3, 2, VAMPIRE, 1) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
            cout << "removing monster: " << game.removeThing(3, 2, DRAGON, 2) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
            cout << "removing monster: " << game.removeThing(3, 2, VAMPIRE, 1) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
            cout << "removing monster: " << game.removeThing(3, 2, SKELETON, 3) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
            cout << "removing monster: " << game.removeThing(5, 3, SKELETON, 3) << endl;
            cout << "removing monster: " << game.removeThing(4, 4, SKELETON, 3) << endl;
            cout << "removing monster: " << game.removeThing(0, -1, SKELETON, 3) << endl;
            cout << "removing monster: " << game.removeThing(-1, 0, SKELETON, 3) << endl;
            cout << "removing monster: " << game.removeThing(3, 2, SKELETON, 30) << endl;
            game.print();
            printGameCellArrayContent(game, 3, 2);
            printGameCellArrayContent(game, 2, 3);
        }
        else if(testCaseNumber == 51)
        {
            //description: test Game::isAllMonstersGone, also simple, with weapons
            int width = 5;  //map width
            int height = 4; //map height
            Game game(width, height);
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "adding monster: " << game.addThing(3, 2, DAGGER, 1) << endl;
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
        }
        else if(testCaseNumber == 52)
        {
            //description: test Game::getMonsterCount, complex
            int width = 5;  //map width
            int height = 4; //map height
            Game game(width, height);
            cout << "getMonsterCount: " << game.getMonsterCount() << endl;
            for(int i=0;i<5;i++)
                for(int j=0;j<4;j++)
                    cout << "adding monster: " << game.addThing(i, j, SKELETON, 1) << endl;
            cout << "getMonsterCount: " << game.getMonsterCount() << endl;
        }
        else if(testCaseNumber == 53)
        {
            //description: test Game::getMonsterCount, more complex
            int width = 5;  //map width
            int height = 4; //map height
            Game game(width, height);
            cout << "getMonsterCount: " << game.getMonsterCount() << endl;
            for(int i=1;i<4;i++)
                for(int j=1;j<4;j++)
                {
                    cout << "adding monster: " << game.addThing(i, j, SKELETON, 1) << endl;
                    cout << "adding monster: " << game.addThing(i, j, VAMPIRE, 2) << endl;
                    cout << "adding monster: " << game.addThing(i, j, DRAGON, 3) << endl;
                }
            cout << "getMonsterCount: " << game.getMonsterCount() << endl;
        }
        else if(testCaseNumber == 54)
        {
            //description: test Game::getHeroX/getHeroY and Game::moveHero, out-of-bound checking
            int width = 2;  //map width
            int height = 2; //map height
            Game game(width, height);
            cout << "getHeroX: " << game.getHeroX() << endl;
            cout << "getHeroY: " << game.getHeroY() << endl;
            cout << "moveHero: " << game.moveHero('w') << endl;
            cout << "moveHero: " << game.moveHero('w') << endl;
            cout << "getHeroX: " << game.getHeroX() << endl;
            cout << "getHeroY: " << game.getHeroY() << endl;
            cout << "moveHero: " << game.moveHero('d') << endl;
            cout << "moveHero: " << game.moveHero('d') << endl;
            cout << "getHeroX: " << game.getHeroX() << endl;
            cout << "getHeroY: " << game.getHeroY() << endl;
            cout << "moveHero: " << game.moveHero('s') << endl;
            cout << "moveHero: " << game.moveHero('s') << endl;
            cout << "getHeroX: " << game.getHeroX() << endl;
            cout << "getHeroY: " << game.getHeroY() << endl;
            cout << "moveHero: " << game.moveHero('a') << endl;
            cout << "moveHero: " << game.moveHero('a') << endl;
            cout << "getHeroX: " << game.getHeroX() << endl;
            cout << "getHeroY: " << game.getHeroY() << endl;
            cout << "moveHero: " << game.moveHero('w') << endl;
            cout << "moveHero: " << game.moveHero('w') << endl;
            cout << "getHeroX: " << game.getHeroX() << endl;
            cout << "getHeroY: " << game.getHeroY() << endl;
        }
        else if(testCaseNumber == 55)
        {
            //description: test of moving hero to get weapons, encounter slightly complicated array of monsters, and die (killed by 3rd skeleton)
            int width = 2;  //map width
            int height = 2; //map height
            Game game(width, height);
            game.addThing(1, 0, DAGGER, 10);
            game.addThing(1, 0, MACE, 2);
            game.addThing(1, 0, SWORD, 10);
            game.addThing(1, 1, VAMPIRE, 3);
            game.addThing(1, 1, SKELETON, 1);
            game.addThing(1, 1, VAMPIRE, 1);
            game.addThing(1, 1, SKELETON, 1);
            game.addThing(1, 1, DRAGON, 1);
            game.addThing(1, 1, SKELETON, 1);
            game.addThing(1, 1, VAMPIRE, 1);
            game.addThing(1, 1, SKELETON, 1);
            game.addThing(1, 1, DRAGON, 1);
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            printGameCellArrayContent(game, 0, 0);
            printGameCellArrayContent(game, 1, 0);
            printGameCellArrayContent(game, 0, 1);
            printGameCellArrayContent(game, 1, 1);
            cout << "moveHero: " << game.moveHero('d') << endl; //get weapons
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            cout << "moveHero: " << game.moveHero('s') << endl; //encounter monsters (not enough appropriate weapons to kill them all)
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            printGameCellArrayContent(game, 0, 0);
            printGameCellArrayContent(game, 1, 0);
            printGameCellArrayContent(game, 0, 1);
            printGameCellArrayContent(game, 1, 1);
        }
        else if(testCaseNumber == 56)
        {
            //description: test of moving hero to get weapons, encounter slightly complicated array of monsters, and die (killed by 1st dragon)
            int width = 2;  //map width
            int height = 2; //map height
            Game game(width, height);
            game.addThing(1, 0, DAGGER, 20);
            game.addThing(1, 0, MACE, 20);
            game.addThing(1, 0, SWORD, 0);
            game.addThing(1, 1, VAMPIRE, 3);
            game.addThing(1, 1, SKELETON, 1);
            game.addThing(1, 1, VAMPIRE, 1);
            game.addThing(1, 1, SKELETON, 1);
            game.addThing(1, 1, DRAGON, 1);
            game.addThing(1, 1, SKELETON, 1);
            game.addThing(1, 1, VAMPIRE, 1);
            game.addThing(1, 1, SKELETON, 1);
            game.addThing(1, 1, DRAGON, 1);
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            printGameCellArrayContent(game, 0, 0);
            printGameCellArrayContent(game, 1, 0);
            printGameCellArrayContent(game, 0, 1);
            printGameCellArrayContent(game, 1, 1);
            cout << "moveHero: " << game.moveHero('d') << endl; //get weapons
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            cout << "moveHero: " << game.moveHero('s') << endl; //encounter monsters (not enough appropriate weapons to kill them all)
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            printGameCellArrayContent(game, 0, 0);
            printGameCellArrayContent(game, 1, 0);
            printGameCellArrayContent(game, 0, 1);
            printGameCellArrayContent(game, 1, 1);
        }
        else if(testCaseNumber == 57)
        {
            //description: test of moving hero to get weapons, encounter monsters, and die empty-handed
            int width = 2;  //map width
            int height = 2; //map height
            Game game(width, height);
            game.addThing(1, 1, VAMPIRE, 1);
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            printGameCellArrayContent(game, 0, 0);
            printGameCellArrayContent(game, 1, 0);
            printGameCellArrayContent(game, 0, 1);
            printGameCellArrayContent(game, 1, 1);
            cout << "moveHero: " << game.moveHero('d') << endl; //get weapons
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            cout << "moveHero: " << game.moveHero('s') << endl; //encounter monsters (not enough appropriate weapons to kill them all)
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            printGameCellArrayContent(game, 0, 0);
            printGameCellArrayContent(game, 1, 0);
            printGameCellArrayContent(game, 0, 1);
            printGameCellArrayContent(game, 1, 1);
        }
        else if(testCaseNumber == 58)
        {
            //description: test of moving hero to get weapons, encounter monsters, and kill them all with all weapons used
            int width = 2;  //map width
            int height = 2; //map height
            Game game(width, height);
            game.addThing(1, 0, DAGGER, 3);
            game.addThing(1, 0, MACE, 3);
            game.addThing(1, 0, SWORD, 4);
            game.addThing(1, 1, VAMPIRE, 3);
            game.addThing(1, 1, SKELETON, 3);
            game.addThing(1, 1, DRAGON, 4);
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            printGameCellArrayContent(game, 0, 0);
            printGameCellArrayContent(game, 1, 0);
            printGameCellArrayContent(game, 0, 1);
            printGameCellArrayContent(game, 1, 1);
            cout << "moveHero: " << game.moveHero('d') << endl; //get weapons
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            cout << "moveHero: " << game.moveHero('s') << endl; //encounter monsters (not enough appropriate weapons to kill them all)
            game.print();
            cout << "isAllMonstersGone: " << game.isAllMonstersGone() << endl;
            cout << "isHeroAlive: " << game.isHeroAlive() << endl;
            printGameCellArrayContent(game, 0, 0);
            printGameCellArrayContent(game, 1, 0);
            printGameCellArrayContent(game, 0, 1);
            printGameCellArrayContent(game, 1, 1);
        }
    }
    else //choice is neither 1 nor 2...
    {
        cout << "So you are crazy... bye!" << endl;
    }

    return 0;
}