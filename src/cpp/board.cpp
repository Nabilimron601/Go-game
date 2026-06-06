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

bool board::isLiberty(int row, int col) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        return grid[row][col] == empty;
    }
    return false;
}

vector<pair<int,int>> board::getGroup(int row, int col, cell color) {
    bool visited[size][size] = {};

    queue<pair<int,int>> q;
    vector<pair<int,int>> group;

    q.push({row, col});
    visited[row][col] = true;

    while (!q.empty()) {
        pair<int,int> curr = q.front();
        q.pop();
        int r = curr.first;
        int c = curr.second;

        group.push_back({r, c});

        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newRow = r + dRow[i];
            int newCol = c + dCol[i];

            if (newRow >= 0 && newRow < size && 
                newCol >= 0 && newCol < size &&
                !visited[newRow][newCol] &&
                grid[newRow][newCol] == color) {

                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
    }

    return group;
}

int board::countLiberties(vector<pair<int,int>> group) {
    bool visited[size][size] = {};
    int count = 0;

    for (auto stone : group) {
        int r = stone.first;
        int c = stone.second;

        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newRow = r + dRow[i];
            int newCol = c + dCol[i];

            if (newRow >= 0 && newRow < size &&
                newCol >= 0 && newCol < size &&
                !visited[newRow][newCol] &&
                grid[newRow][newCol] == empty) {
                
                visited[newRow][newCol] = true;
                count++;
            }
        }
    }
    return count;
}