#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Soldier
{

private:
    int HP;
    int max_HP;
    int damage;
    int num;

public:
    Soldier(int max, int damage, int num) : max_HP(max),HP(max), damage(damage), num(num) {}
    virtual ~Soldier() {};
    virtual void BOOM(vector<vector<Soldier *>> &board, pair<int, int> dest) = 0;
    int getnum() { return this->num; };
    void set_HP(int num) { this->HP = num; };
    int getCurrHP() { return this->HP; };
    int getdamage() { return this->damage; };
    int getMaxHP() { return this->max_HP;};
};