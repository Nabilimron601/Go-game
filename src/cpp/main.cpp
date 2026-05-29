#include <iostream>
#include "board.h"
using namespace std;

int main(){
        board board;
    int row, col;
    cell currentPlayer = black;

    cout << "=== Permainan Go 9x9 ===" << endl;

    while (true) {
        board.display();
        cout << (currentPlayer == black ? "Hitam" : "Putih") << " - masukkan baris dan kolom: ";
        cin >> row >> col;

        if (board.stone(row, col, currentPlayer)) {
            currentPlayer = (currentPlayer == black) ? white : black;
        }
    }

    return 0;
}
