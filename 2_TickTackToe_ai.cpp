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
            return (board[i][0] == 'H') ? -1 : 1; // 'H' for human, return -1 for human win, 1 for AI win
        }
        if (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == 'H') ? -1 : 1; 
        }
    }
    if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == 'H') ? -1 : 1; // Main diagonal
    }
    if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == 'H') ? -1 : 1; // Anti-diagonal
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

int minimax(int depth, bool toMaximize){
    int status = checkStatus();
    if (status != 2) {
        // Return the score based on the status, adjusting for depth
        if (status == -1) return -1; // Human wins, penalty for depth
        if (status == 1) return 1;
        return 0; // Tie
    }

    if(toMaximize){
        int best = -1000;
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                if(board[i][j] == '.'){
                    board[i][j] = 'A';
                    int score = minimax(depth + 1, false);
                    board[i][j] = '.';
                    if(score > best){
                        best = score;
                    }
                }
            }
        }
        return best;
    }else{
        int best = 1000;
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                if(board[i][j] == '.'){
                    board[i][j] = 'H';
                    int score = minimax(depth + 1, true);
                    board[i][j] = '.';
                    if(score < best){
                        best = score;
                    }
                }
            }
        }
        return best;
    }
}

void findBestMove(){
    int status = checkStatus();
    if(status != 2){
        string winner = status == -1 ? "H" : "AI";
        if(status != 0){
            cout << winner + " won this game!" << endl;
        }
        else{
            cout << "TIE!" << endl;
        }
        exit(0);
    }

    int best = -1000;
    int idx1 = -1;
    int idx2 = -1;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(board[i][j] == '.'){
                board[i][j] = 'A';
                int score = minimax(0, false);
                board[i][j] = '.';
                if(score > best){
                    best = score;
                    idx1 = i;
                    idx2 = j;
                }
            }
        }
    }
    board[idx1][idx2] = 'A';
}

void startGame(){
    int i, j;
    while (true){
        int status = checkStatus();
        if(status != 2){
            string winner = status == -1 ? "H" : "AI";
            if(status != 0){
                cout << winner + " won this game!" << endl;
            }
            else{
                cout << "TIE!" << endl;
            }
            break;
        }
        printBoard();
        cout << "Enter Cordinates: " << endl;
        cin >> i >> j;
        if((i < 3 && i >= 0) && (j >= 0 && j < 3)){
            board[i][j] = 'H';
            findBestMove();
        }else{
            cout << "Enter valid cordinates!" << endl;
        }
    }
}

int main() {
    startGame();
    return 0;
}