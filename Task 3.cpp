#include <iostream>
#include <vector>

using namespace std;


void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; 
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; 
        }
    }

    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; 
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; 
    }

    return false;
}


bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false; 
        }
    }
    return true; 
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (true) {
        do {
            cout << "Current Board:" << endl;
            displayBoard(board);

            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column, e.g., 1 2): ";
            cin >> row >> col;

            
            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
                board[row - 1][col - 1] = currentPlayer;

                
                if (checkWin(board, currentPlayer)) {
                    gameWon = true;
                } else if (checkDraw(board)) {
                    gameDraw = true;
                }

                
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        } while (!gameWon && !gameDraw);

        cout << "Current Board:" << endl;
        displayBoard(board);

        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }

        char playAgain;
        cout << "Play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            break; 
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
        gameWon = false;
        gameDraw = false;
    }

    return 0;
}
