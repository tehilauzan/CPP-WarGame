#include "ParamedicCommander.hpp"

void ParamedicCommander::BOOM(vector<vector<Soldier *> > &board, pair<int, int> dest) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            Soldier *s = board[i][j];
            if (s != nullptr) {
                if (Paramedic *fs = dynamic_cast<Paramedic *>(s)) {

                    ParamedicCommander *fc = dynamic_cast<ParamedicCommander *>(s);
                    if ((fc == nullptr) || (i == dest.first && j == dest.second)) {
                        if (fs->getnum() == board[dest.first][dest.second]->getnum()) {
                            fs->Paramedic::BOOM(board, make_pair(i, j));
                        }
                    }
                }
            }
        }
    }
}