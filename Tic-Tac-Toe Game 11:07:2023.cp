//
//  main.cpp
//  Tic-Tac-Toe Game
//
//  Created by Adam Balatka on 11/7/23.
//

#include <iostream>
using namespace std;

char board [3][3] = {{'1', '2', '3' ,}, {'4', '5', '6' ,}, {'7', '8', '9' ,}};
char currentMarker; // for X and O in the game
int currentPlayer; // for player who is taking a turn

void drawBoard(){ // function to print the board
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "-----------\n";
    
}

bool placeMarker (int slot){
    int row = slot / 3;
    int column;
    
    if (slot % 3 == 0){
        row = row - 1;
        column = 2;
    }
    else {
        column = (slot % 3) - 1;
    }
    
    if (board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = currentMarker;
        return true;
    }
    else {
        return false;
    }
    
}

// function for game logic; for the winner; 3 windows on the board must have the same character or value (horizontally, vertically, diagonally)
int winner(){
    for (int i = 0; i < 3; i++){
        
        // Rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return currentPlayer;
        }
        
        // Columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return currentPlayer;
        }
    }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return currentPlayer;
    }
    
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return currentPlayer;
    }
    
    return 0;
}

//function allowing to switch between X and O markers; function to switch players after their turn
void swapPlayerAndMarker(){
    if (currentMarker == 'X'){
        currentMarker = 'O';
    }
    else {
        currentMarker = 'X';
    }
    
    if (currentPlayer == 1){
        currentPlayer = 2;
    }
    else {
        currentPlayer = 1;
    }
}

void game()
    {
    
    cout << "Player 1, please select either O or X: ";
    char playerOneMarker;
    cin >> playerOneMarker;
        
    while (playerOneMarker != 'O' && playerOneMarker != 'X'){ // maybe OR expression instead of AND
        cout << "Invalid value. Please select either O or X: ";
        cin >> playerOneMarker;
    }
    currentPlayer = 1;
    currentMarker = playerOneMarker;
        
    drawBoard();
        
    int playerWon = 0;
    int slot;
    int i;
        
    for (i = 0; i < 9; i++){
        cout << "It is Player's " << currentPlayer << " turn. Please enter your move: ";
        cin >> slot;
        if (slot < 1 || slot > 9){
            cout << "Invalid value. This move is outside of the accepted perimeters and thus, it is invalid. Please try another move. ";
            i--;
            continue;
        }
        if (!placeMarker(slot)){
            cout << "Invalid move. This move has already been taken. Please try another move. ";
            i--;
            continue;
        }
        drawBoard();
            
        playerWon = winner();
        if (playerWon == 1){
            cout << "Player 1 has won! Well played!" << endl;
            break;
        }
        if (playerWon == 2){
            cout << "Player 2 has won! Well played!" << endl;
            break;
        }
            
        swapPlayerAndMarker();
            
        }
    if (playerWon == 0){
        cout << "It's a tie! Let's play again!" << endl;
        
    }
}

int main() {
    game();
    
    return 0;
}
