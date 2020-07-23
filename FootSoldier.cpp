#include "FootSoldier.hpp"
#include "math.h"

void FootSoldier::BOOM(vector<vector<Soldier *> > &board, pair<int, int> loaction) {

    double closest = board.size() * board.size();
    int indexi=0, indexj=0;
    int found = 0;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            Soldier *s;
            s = board[i][j];
            if (s != nullptr && (s->getnum() != board[loaction.first][loaction.second]->getnum())) {
                double dist = sqrt((i - loaction.first) * (i - loaction.first) + (j - loaction.second) * (j - loaction.second));
                if (dist < closest) {
                    closest = dist;
                    indexi = i;
                    indexj = j;
                    found = 1;
                }
            }
        }
    }if (indexi==INFINITY){
        return;
    }
    if (found) {
        Soldier *s = board[indexi][indexj];
        int hp = s->getCurrHP() - board[loaction.first][loaction.second]->getdamage();
        if (hp <= 0) {
            board[indexi][indexj] = nullptr;
        } else {
            s->set_HP(hp);
        }

    }
}