#include <iostream>

using namespace std;

char gameBoard[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int playerSpot;
int row, col;
char turn = 'X';
bool isDraw = false;

void printBoard() {
    
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            printf(" %c |", gameBoard[x][y]);
        }
        printf("\n-----------\n");
    } 
}

void takeTurn() {
    if(turn == 'X'){
        cout << "Player - 1 [X] turn : ";
    }
    else if(turn == 'O') {
        cout << "Player - 2[O] turn : ";
    }

    cin >> playerSpot;

    switch(playerSpot) {
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
        default: cout << "Move not valid!";
    }

    if(turn == 'X' && gameBoard[row][col] != 'X' && gameBoard[row][col] != 'O'){
        gameBoard[row][col] = turn;
        turn = 'O';
    }
    else if(turn == 'O' && gameBoard[row][col] != 'O' && gameBoard[row][col] != 'X'){
        gameBoard[row][col] = turn;
        turn = 'X';
    }
    else {
        cout << "Position alreay filled...\nTry again!";
        takeTurn();
    }

}

bool gameOver() {
    for(int i = 0; i < 3; i++){
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2] || 
            gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i]) {
                return false;
        }
    }

    if(gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2] ||
        gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0]){
            return false;
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            if(gameBoard[i][j] != 'X' && gameBoard[i][j] != 'O'){
                return true;
            }
        }
    }

    isDraw = true;
    return false;
}

int main() {
    cout << "            T I C K -- T A C -- T O E            " << endl;
    while(gameOver()){
        printBoard();
        takeTurn();
        gameOver();
    }

    if(turn == 'X' && isDraw == false) {
        cout << "O Has Won!" << endl;
        printBoard();
    }
    else if(turn == 'O' && isDraw == false) {
        cout << "X Has Won!" << endl;
        printBoard();
    }
    else{
        cout << "Draw!" << endl;
        printBoard();
    }

    return 0;
}