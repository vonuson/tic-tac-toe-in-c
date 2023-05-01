#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void draw_board() {
        printf("\\   1   2   3\n");
    printf("  +---+---+---+\n");
    printf("1 | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("  +---+---+---+\n");
    printf("2 | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("  +---+---+---+\n");
    printf("3 | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
    printf("  +---+---+---+\n");
}

int check_win(char player) {
    int row, col;

    // Check rows
    for (row = 0; row < 3; row++) {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (col = 0; col < 3; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

void random_move() {
    int row, col;

    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = 'O';
}

void ai_move() {
    int row, col;

    // Check rows
    for (row = 0; row < 3; row++) {
        if (board[row][2] == ' ' && ((board[row][0] == 'X' && board[row][1] == 'X') || (board[row][0] == 'O' && board[row][1] == 'O'))) {
            board[row][2] = 'O';
            return;
        }
        if (board[row][1] == ' ' && ((board[row][0] == 'X' && board[row][2] == 'X') || (board[row][0] == 'O' && board[row][2] == 'O'))) {
            board[row][1] = 'O';
            return;
        }
        if (board[row][0] == ' ' && ((board[row][1] == 'X' && board[row][2] == 'X') || (board[row][1] == 'O' && board[row][2] == 'O'))) {
            board[row][0] = 'O';
            return;
        }
    }

    // Check columns
    for (col = 0; col < 3; col++) {
        if (board[2][col] == ' ' && ((board[0][col] == 'X' && board[1][col] == 'X') || (board[0][col] == 'O' && board[1][col] == 'O'))) {
            board[2][col] = 'O';
            return;
        }
        if (board[1][col] == ' ' && ((board[0][col] == 'X' && board[2][col] == 'X') || (board[0][col] == 'O' && board[2][col] == 'O'))) {
            board[1][col] = 'O';
            return;
        }
        if (board[0][col] == ' ' && ((board[1][col] == 'X' && board[2][col] == 'X') || (board[1][col] == 'O' && board[2][col] == 'O'))) {
            board[0][col] = 'O';
            return;
        }
    }

    // Check diagonal from top left to bottom right
    if (board[2][2] == ' ' && ((board[0][0] == 'X' && board[1][1] == 'X') || (board[0][0] == 'O' && board[1][1] == 'O'))) {
        board[2][2] = 'O';
        return;
    }
    if (board[1][1] == ' ' && (board[0][0] == 'X' && board[2][2] == 'X') || (board[0][0] == 'O' && board[2][2] == 'O')) {
        board[1][1] = 'O';
        return;
    }
    if (board[0][0] == ' ' && (board[1][1] == 'X' && board[2][2] == 'X') || (board[1][1] == 'O' && board[2][2] == 'O')) {
        board[0][0] = 'O';
        return;
    }

    // Check diagonal from top right to bottom left
    if (board[2][0] == ' ' && (board[0][2] == 'X' && board[1][1] == 'X') || (board[0][2] == 'O' && board[1][1] == 'O')) {
        board[2][0] = 'O';
        return;
    }
    if (board[1][1] == ' ' && (board[0][2] == 'X' && board[2][0] == 'X') || (board[0][2] == 'O' && board[2][0] == 'O')) {
        board[1][1] = 'O';
        return;
    }
    if (board[0][2] == ' ' && (board[1][1] == 'X' && board[2][0] == 'X') || (board[1][1] == 'O' && board[2][0] == 'O')) {
        board[0][2] = 'O';
        return;
    }

    random_move();
}

int main() {
    int row, col;
    int turn = 0;
    int moves = 0;

    while (!check_win('X') && !check_win('O') && moves < 9) {
        draw_board();

        if (turn == 0) {
            printf("Enter row and column (1-3) for X: ");
            scanf("%d %d", &row, &col);

            if (board[row-1][col-1] == ' ') {
                board[row-1][col-1] = 'X';
                turn = 1;
                moves++;
            }
            else {
                printf("Invalid move. Please try again.\n");
            }
        }
        else {
            printf("AI is thinking...\n");
            ai_move();
            turn = 0;
            moves++;
        }
    }

    draw_board();

    if (check_win('X')) {
        printf("Congratulations! You win!\n");
    }
    else if (check_win('O')) {
        printf("Sorry, you lose. Better luck next time.\n");
    }
    else {
        printf("It's a tie!\n");
    }

    return 0;
}
