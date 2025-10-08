#include <iostream>
#include <windows.h>  // for colors
using namespace std;

// Function to set console text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to display the title
void displayTitle() {
    setColor(14); // Light Yellow
    cout << "==========================" << endl;
    cout << "       TIC TAC TOE        " << endl;
    cout << "==========================" << endl;
    setColor(7); // Reset to default
}

// Function to print the Tic Tac Toe board
void printBoard(char arr[3][3], int size) {
    cout << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == 'X') setColor(11); // Light Blue for X
            else if (arr[i][j] == 'O') setColor(13); // Light Magenta for O
            else setColor(7); // Default white
            cout << " " << arr[i][j] << " ";
            setColor(8); // Gray for grid
            if (j < size - 1) cout << "|";
            setColor(7);
        }
        cout << endl;
        if (i < size - 1) {
            setColor(8);
            cout << "---+---+---" << endl;
            setColor(7);
        }
    }
}

// Function to take player input
void playerMove(char arr[3][3], char player) {
    int row = 0, col = 0;
    bool move = false;

    while (!move) {
        setColor(10);
        cout << "\nPlayer " << player << ", enter row (0-2): ";
        setColor(7);
        cin >> row;
        setColor(10);
        cout << "Player " << player << ", enter column (0-2): ";
        setColor(7);
        cin >> col;

        if (row >= 0 && row <= 2 && col >= 0 && col <= 2) {
            if (arr[row][col] == ' ') {
                arr[row][col] = player;
                move = true;
            }
            else {
                setColor(12);
                cout << "That spot is already taken. Try again." << endl;
                setColor(7);
            }
        }
        else {
            setColor(12);
            cout << "Row and column must be between 0 and 2. Try again." << endl;
            setColor(7);
        }
    }
}

// Function to check if a player has won
bool checkWin(char arr[3][3], char player) {
    int size = 3;
    for (int i = 0; i < size; i++) {
        if ((arr[i][0] == player && arr[i][1] == player && arr[i][2] == player) ||
            (arr[0][i] == player && arr[1][i] == player && arr[2][i] == player)) {
            return true;
        }
    }
    if ((arr[0][0] == player && arr[1][1] == player && arr[2][2] == player) ||
        (arr[0][2] == player && arr[1][1] == player && arr[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check for draw
bool checkDraw(char arr[3][3]) {
    int size = 3;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to display final board and result
void displayResult(char arr[3][3], char resultType, char player) {
    displayTitle();
    printBoard(arr, 3);

    if (resultType == 'W') {
        setColor(10);
        cout << "\n Player " << player << " wins! " << endl;
        setColor(12);
    }
    else if (resultType == 'D') {
        setColor(6);
        cout << "\n It's a draw!" << endl;
        setColor(7);
    }
}

// Main game loop
void playGame() {
    int size = 3;
    char arr[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
    char player = 'X';
    bool gameover = false;

    displayTitle();

    while (true) {
        printBoard(arr, size);
        playerMove(arr, player);

        if (checkWin(arr, player)) {
            displayResult(arr, 'W', player);
            break;
        }

        if (checkDraw(arr)) {
            displayResult(arr, 'D', player);
            break;
        }

        // Switch player
        if (player == 'X') player = 'O';
        else player = 'X';
    }
}

// Main function
int main() {
    playGame();
    return 0;
}
