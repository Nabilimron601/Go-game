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