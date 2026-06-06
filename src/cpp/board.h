#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int size = 9;

enum cell{
    empty = 0,
    black = 1,
    white = 2
};

class board{
    private: 
    cell grid[size][size];

    public:
    board();
    void display();
    bool stone(int row, int col, cell player);
    cell getcell (int row, int col);
    bool isLiberty(int row, int col);
    vector<pair<int,int>> getGroup(int row, int col, cell color);
    int countLiberties(vector<pair<int,int>> group);
};

#endif
