#include <iostream>

// Function prototype to print the board
void printBoard(char board[3][3]);

int main() {
    // Initialize the 3x3 board with spaces
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char currentPlayer = 'X';
    int row, col;
    int turns = 0;

    std::cout << "--- Welcome to Tic-Tac-Toe! ---\n\n";

    // Play for a maximum of 9 turns
    while (turns < 9) {
        printBoard(board);

        std::cout << "Player " << currentPlayer << ", enter your move.\n";
        std::cout << "Row (1-3): ";
        std::cin >> row;
        std::cout << "Column (1-3): ";
        std::cin >> col;

        // Convert 1-based user input to 0-based array indexing
        int r = row - 1;
        int c = col - 1;

        // Validate user input bounds and ensure the cell is empty
        if (r >= 0 && r < 3 && c >= 0 && c < 3 && board[r][c] == ' ') {
            board[r][c] = currentPlayer; // Set the cell to X or O
            turns++;                     // Increment turn counter

            // Switch player for the next turn
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            }
            else {
                currentPlayer = 'X';
            }
            std::cout << "\nMove placed successfully!\n\n";
        }
        else {
            std::cout << "\nInvalid move! That spot is either out of bounds or already taken. Try again.\n\n";
        }
    }

    // Print final board state
    std::cout << "--- Game Over ---\n";
    printBoard(board);

    return 0;
}

// Function to print the board to the console
void printBoard(char board[3][3]) {
    std::cout << "  1   2   3\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) {
            std::cout << "  ---------\n";
        }
    }
    std::cout << "\n";
}