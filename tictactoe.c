#include <stdio.h>

#define SIZE 3

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int isMoveValid(char board[SIZE][SIZE], int row, int col);
int checkWin(char board[SIZE][SIZE]);
int isBoardFull(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    int row, col, currentPlayer = 1;

    initializeBoard(board);

    do {
        printBoard(board);

        // Determine current player
        currentPlayer = (currentPlayer % 2) ? 1 : 2;

        // Get player move
        printf("Player %d, enter row (1-3) and column (1-3) separated by space: ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Adjust row and column to array indices
        row--;
        col--;

        // Check if the move is valid
        if (isMoveValid(board, row, col)) {
            board[row][col] = (currentPlayer == 1) ? 'X' : 'O';

            // Check for a win
            if (checkWin(board)) {
                printBoard(board);
                printf("Player %d wins!\n", currentPlayer);
                break;
            }

            // Check for a draw
            if (isBoardFull(board)) {
                printBoard(board);
                printf("It's a draw!\n");
                break;
            }

            // Switch to the next player
            currentPlayer++;
        } else {
            printf("Invalid move. Try again.\n");
        }
    } while (1);

    return 0;
}

// Function to initialize the game board
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the game board
void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

// Function to check if a move is valid
int isMoveValid(char board[SIZE][SIZE], int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

// Function to check for a win
int checkWin(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return 1; // Win
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1; // Win
    }

    return 0; // No win
}

// Function to check if the board is full
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}