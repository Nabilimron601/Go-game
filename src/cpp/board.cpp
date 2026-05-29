#include <iostream>
#include "board.h"
using namespace std;

board::board(){
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            grid[i][j] = empty;
}

void board::display() {
    cout << "  ";
    for (int j = 0; j < size; j++)
        cout << j << " ";
    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << i << " ";
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == empty) cout << ". ";
            else if (grid[i][j] == black) cout << "B ";
            else cout << "W ";
        }
        cout << endl;
    }
}
bool board::stone(int row, int col, cell player){
    if (row < 0 || row >= size || col < 0 || col >= size) {
        cout << "Posisi di luar papan!" << endl;
        return false;
    }
    if (grid[row][col] != empty) {
        cout << "Posisi sudah terisi" << endl;
        return false;
    }
    grid[row][col] = player;
    return true;
}

cell board::getcell(int row, int col) {
    return grid[row][col];
}