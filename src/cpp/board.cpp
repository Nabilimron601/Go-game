#include <iostream>
#include "board.h"
using namespace std;

board::board(){
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            grid[i][j] = empty;
}