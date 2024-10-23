#include <iostream>
using namespace std;

char board[3][3] = {
    {'.', '.', '.'},
    {'.', '.', '.'},
    {'.', '.', '.'}
};

void printBoard(){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int checkStatus() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == 'X') ? -1 : 1; // 'H' for human, return -1 for human win, 1 for AI win
        }
        if (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == 'X') ? -1 : 1; 
        }
    }
    if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == 'X') ? -1 : 1; // Main diagonal
    }
    if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == 'X') ? -1 : 1; // Anti-diagonal
    }
    bool isDraw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '.') {
                isDraw = false;
                break;
            }
        }
    }

    return isDraw ? 0 : 2; // Return 0 for draw, 2 for ongoing game
}

void startGame(){
    int i, j;
    int player = 0;
    while (true){
        int status = checkStatus();
        if(status != 2){
            string winner = status == -1 ? "X" : "O";
            if(status != 0){
                cout << winner + " won this game!" << endl;
            }
            else{
                cout << "TIE!" << endl;
            }
            break;
        }
        printBoard();
        cout << "Enter Cordinates Player "<< player << ": " << endl;
        cin >> i >> j;
        if((i < 3 && i >= 0) && (j >= 0 && j < 3) && board[i][j] == '.'){
            board[i][j] = player == 0 ? 'X' : 'O';
            player = player == 0 ? 1 : 0;
        }else{
            cout << "Enter valid cordinates!" << endl;
        }
    }
}

int main() {
    startGame();
    return 0;
}