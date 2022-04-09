#include "game.h"
#include <iostream>
using namespace std;
//do NOT include anything else, write your code below

Game::Game(int width, int height):width(width), height(height){
    cells = new Cell* [height];
    for (int i = 0; i < height; ++i){
        cells[i] = new Cell [width];
    }

}

Game::Game(const Game& another):width(another.width), height(another.height), heroStatus(another.heroStatus){
    cells = new Cell* [height];
    for (int i = 0; i < height; ++i){
        cells[i] = new Cell [width];
        for (int j = 0; j < width; ++j){
            for (int k = 0; k < another.cells[i][j].getThingCount(); ++k){
                cells[i][j].addThing(another.cells[i][j].getThing(k).getType(), 1);
            }
        }
    }

}

Game::~Game(){
    for (int i = 0; i < height; ++i){
        delete [] cells[i];
    }
    delete [] cells;
}

bool Game::addThing(int x, int y, ThingType type, int quantity){
    if ( x <0 || y < 0 || x >= width || y >= height){
        return false;
    }
    return cells[y][x].addThing(type, quantity);
}

bool Game::removeThing(int x, int y, ThingType type, int quantity){
    if ( x <0 || y < 0 || x >= width || y >= height){
        return false;
    }
    return cells[y][x].removeThing(type, quantity);
}

bool Game::moveHero(char direction){
    
    // change the coordinate of the hero
    bool valid_move = true;
    switch(direction)
    {
        case 'w': ((heroStatus.y - 1) < 0 )? valid_move = false : heroStatus.y -= 1; break;
        case 's': ((heroStatus.y + 1) >= height )? valid_move = false : heroStatus.y += 1; break;
        case 'a': ((heroStatus.x - 1) < 0 )? valid_move = false : heroStatus.x -= 1; break;
        case 'd': ((heroStatus.x + 1) >= width )? valid_move = false : heroStatus.x += 1; break;
    }

    if (!valid_move){
        return false;
    }

    // if there are weapons in cell, update it
    while (cells[heroStatus.y][heroStatus.x].hasWeapons()){
        if (cells[heroStatus.y][heroStatus.x].hasType(MACE)){
            heroStatus.maceCount += 1;
            removeThing(heroStatus.x, heroStatus.y, MACE);
        }

        if (cells[heroStatus.y][heroStatus.x].hasType(DAGGER)){
            heroStatus.daggerCount += 1;
            removeThing(heroStatus.x, heroStatus.y, DAGGER);
        }
        if (cells[heroStatus.y][heroStatus.x].hasType(SWORD)){
            heroStatus.swordCount += 1;
            removeThing(heroStatus.x, heroStatus.y, SWORD);
        }
    }
    // if there are monsters in cell, kill it if has weapon

    while (cells[heroStatus.y][heroStatus.x].hasMonsters()){

        if (cells[heroStatus.y][heroStatus.x].getThing(0).getType() == DRAGON){
            if (heroStatus.swordCount != 0){
                heroStatus.swordCount -= 1;
                removeThing(heroStatus.x, heroStatus.y, DRAGON);
            }else{
                heroStatus.alive = false;
                break;
            }
        }

        if (!cells[heroStatus.y][heroStatus.x].hasMonsters()){
            break;
        }

        if (cells[heroStatus.y][heroStatus.x].getThing(0).getType() ==VAMPIRE){
            if (heroStatus.daggerCount != 0){
                heroStatus.daggerCount -= 1;
                removeThing(heroStatus.x, heroStatus.y, VAMPIRE);
            }else{
                heroStatus.alive = false;
                break;
            }
        }

        if (!cells[heroStatus.y][heroStatus.x].hasMonsters()){
            break;
        }
        
        if (cells[heroStatus.y][heroStatus.x].getThing(0).getType() == SKELETON){
            if (heroStatus.maceCount != 0){
                heroStatus.maceCount -= 1;
                removeThing(heroStatus.x, heroStatus.y, SKELETON);
            }else{
                heroStatus.alive = false;
                break;
            }
        }
    }
    return true;
}

bool Game::isHeroAlive() const{
    return heroStatus.alive;
}

bool Game::isAllMonstersGone() const{
    return (getMonsterCount())? false : true;
}

int Game::getMonsterCount() const{
    int count = 0;
    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            if(cells[i][j].hasMonsters()){
                count += cells[i][j].getThingCount(DRAGON);
                count += cells[i][j].getThingCount(SKELETON);
                count += cells[i][j].getThingCount(VAMPIRE);
            }
        }
    }
    return count;
}

int Game::getHeroX() const{
    return heroStatus.x;
}

int Game::getHeroY() const{
    return heroStatus.y;
}