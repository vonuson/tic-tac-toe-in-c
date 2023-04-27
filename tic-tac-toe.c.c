#include <stdio.h>

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
    int i, j;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
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

    // No win
    return 0;
}

int main() {
    int row, col;
    char player = 'X';
    int turns = 0;

    printf("Welcome to Tic Tac Toe!\n");
    printf("-----------------------\n");
    draw_board();

    while (turns < 9) {
        printf("\nPlayer %c's turn. Enter row (1-3) and column (1-3): ", player);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input. Please enter row (1-3) and column (1-3).\n");
            continue;
        }

        if (board[row-1][col-1] != ' ') {
            printf("That space is already taken. Please choose another.\n");
            continue;
        }

        board[row-1][col-1] = player;
        draw_board();

        if (check_win(player)) {
            printf("\nPlayer %c wins!\n", player);
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
        turns++;
    }

    printf("\nIt's a tie!\n");

    return 0;
}