#include "Board.hpp"

using namespace std;

namespace WarGame {
    Soldier *&Board::operator[](std::pair<int, int> location) {
        return board[location.first][location.second];
    }

    Soldier *Board::operator[](std::pair<int, int> location) const {
        return board[location.first][location.second];
    }

    void WarGame::Board::move(uint player_number, std::pair<int, int> source, Board::MoveDIR direction) {
        if (board[source.first][source.second] == nullptr ||
            board[source.first][source.second]->getnum() != player_number) {

            throw exception();
        }
        cout<< "pair first: "<<source.first<<endl;
        cout<< "pair secand: "<<source.second<<endl;
        Soldier *s = WarGame::Board::board[source.first][source.second];
        int source_x = source.first;
        int source_y = source.second;
        pair<int, int> point;

        switch (direction) {
            case WarGame::Board::Up:
                if (((source.first + 1) < Board::board.size()) &&
                    board[source_x + 1][source_y] == nullptr) {
                    Board::board[source_x][source_y] = nullptr;
                    Board::board[source_x + 1][source_y] = s;
                    point.first = source_x + 1;
                    point.second = source_y;
                } else {
                    throw exception();
                }
                break;
            case WarGame::Board::Down:
                if (((source.first - 1) < Board::board.size()) &&
                    (board[source_x - 1][source_y] == nullptr)) {
                    Board::board[source_x][source_y] = nullptr;
                    Board::board[source_x - 1][source_y] = s;
                    point.first = source_x - 1;
                    point.second = source_y;
                } else {
                    throw exception();
                }
                break;
            case WarGame::Board::Left:
                if (((source.second - 1) < Board::board[0].size()) &&
                    board[source_x][source_y - 1] == nullptr) {
                    Board::board[source_x][source_y] = nullptr;
                    Board::board[source_x][source_y - 1] = s;
                    point.first = source_x;
                    point.second = source_y - 1;
                } else {
                    throw exception();
                }
                break;
            case WarGame::Board::Right:
                if (((source.second + 1) < Board::board[0].size()) &&
                    board[source_x][source_y + 1] == nullptr) {
                    Board::board[source_x][source_y] = nullptr;
                    Board::board[source_x][source_y + 1] = s;
                    point.first = source_x;
                    point.second = source_y + 1;
                } else {
                    throw exception();
                }
                break;
        }
        cout<<"after switch"<<endl;
        board[point.first][point.second]->BOOM(board, point);
    }

    void Board::printboard() {
        for (int i = 0; i < this->board.size(); i++) {
            for (int j = 0; j < this->board[i].size(); j++) {
                if (this->board[i][j])

                    cout << "  " << this->board[i][j]->getnum() << "  " << this->board[i][j]->getCurrHP()
                    << "  "<<typeid(*this->board[i][j]).name();
                else
                    cout << "  ------  ";

            }
            cout << "" << endl;

        }
        cout << "   " << endl;
        cout << "   " << endl;

        cout << "   " << endl;
        cout << "   " << endl;

    }


    bool Board::has_soldiers(uint player_number) const {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                Soldier *s = board[i][j];
                if (s != nullptr) {
                    if (s->getnum() == player_number) {
                        return true;
                    }

                }
            }
        }
        return false;
    }

}