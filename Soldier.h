//
// Created by netanel on 26/05/2020.
//

#ifndef WARGAME_THILA_SOLDIER_H
#define WARGAME_THILA_SOLDIER_H


class Soldier {
public:
    int health;
    int damage;
    int num_team;
    int hp;

public:
    Soldier(int h,int d,int num_p):health(h),damage(d),num_team(num_p){}
    int get_health(){return health;}
    void set_health(int health){this->health=health;}
    int get_damage(){return damage;}
    int get_num_player(){return num_team;}

    virtual ~Soldier(){
    }
};
//////////////////////
class FootSoldier: public Soldier {
public:
    FootSoldier(int num_p): Soldier(100, 10, num_p){}

};
/////////////////////
class FootCommander : public FootSoldier {
public:
    FootCommander(int num_p): FootSoldier(num_p){
        this->damage=150;
        this->health=20;
    }


};
/////////////////////
class Sniper : public Soldier {
public:
    Sniper(int num_p): Soldier(100, 50, num_p){}

};
/////////////////////
class SniperCommander : public Sniper {
public:
    SniperCommander(int num_p):Sniper(num_p){
        this->damage=100;
        this->health=120;
    }

};
/////////////////////
class Paramedic : public Soldier {
public:
  Paramedic(int num_p): Soldier(100, 0, num_p){}
};
/////////////////////
class ParamedicCommander : public Paramedic {

    ParamedicCommander(int num_p):Paramedic(num_p){
        this->health=200;
    }




};



#endif //WARGAME_THILA_SOLDIER_H
