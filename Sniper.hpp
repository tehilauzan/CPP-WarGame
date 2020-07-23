#pragma once

#include "Soldier.hpp"

using namespace std;

const int MAX_HP_S = 100;
const int ACTION_S = 50;

class Sniper : public Soldier {

public:
    Sniper(uint pNUM): Soldier(MAX_HP_S,ACTION_S,pNUM ) {}
    Sniper(uint pNUM,uint maxhp,uint act): Soldier(maxhp,act,pNUM ) {}
    void BOOM(vector<vector<Soldier*>> &board,pair<int,int> dest);
};