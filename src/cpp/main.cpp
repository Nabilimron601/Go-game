#include <iostream>
#include "Board.h"
using namespace std;

int main() {
    board b;
    int row, col;
    cell currentPlayer = black;

    cout << "=== Permainan Go 9x9 ===" << endl;

    while (true) {
        b.display();
        cout << (currentPlayer == black ? "Hitam" : "Putih") << " - masukkan baris dan kolom: ";
        cin >> row >> col;

        if (b.stone(row, col, currentPlayer)) {
            cell opponent = (currentPlayer == black) ? white : black;
            b.capture(row, col, opponent);
            currentPlayer = opponent;
        }
    }

    return 0;
}