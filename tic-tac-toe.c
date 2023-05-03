#include <stdio.h>
#include <stdlib.h>

char player = 'X', opponent = 'O';
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

/*
 * Function: check_win 
 * --------------------
 * check if the game is won
 *
 *  returns: the state of the game
 *           -1 -> the game ended in a tie
 *           0 -> the game ended and O won
 *           1 -> the game ended and X won
 *           2 -> the game is in-progress
 */
int check_win() {
    int row, col, empty_cells = 0;
    char first;
    
    // Check rows for a win
    for (row = 0; row < 3; row++) {
        first = board[row][0];
        if (first != ' ') {
            if (first == board[row][1] && first == board[row][2]) {
                return first == player;
            }
        } else {
            empty_cells++;
        }
    }
    
    // Check columns for a win
    for (col = 0; col < 3; col++) {
        first = board[0][col];
        if (first != ' ') {
            if (first == board[1][col] && first == board[2][col]) {
                return first == player;
            }
        } else {
            empty_cells++;
        }
    }
    
    // Check diagonal from top left to bottom right for a win
    first = board[0][0];
    if (first != ' ') {
        if (first == board[1][1] && first == board[2][2]) {
            return first == player;
        }
    } else {
        empty_cells++;
    }
    
    // Check diagonal from top right to bottom left for a win
    first = board[0][2];
    if (first != ' ') {
        if (first == board[1][1] && first == board[2][0]) {
            return first == player;
        }
    } else {
        empty_cells++;
    }
    
    // Check if there are any empty cells left
    if (empty_cells == 0) {
        return -1;
    } else {
        return 2;
    }
}

int is_board_full() {
    int row, col;

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int minimax(int depth, int is_maximizing)
{
    int score = check_win();
    if (score == 1) {
        return 10 - depth;
    }
    else if (score == 0) {
        return score - 10;
    }
    else if (score == -1 && is_board_full()) {
        return 0;
    }

    // If this maximizer's move
    if (is_maximizing)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]==' ')
                {
                    // Make the move
                    board[i][j] = player;

                    // Call minimax recursively and choose
                    // the maximum value
                    
                    int result = minimax(depth+1, !is_maximizing);
                    best = best >= result ? best : result;

                    // Undo the move
                    board[i][j] = ' ';
            }
        }
    }
        return best;
    }

    // If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]==' ')
                {
                    // Make the move
                    board[i][j] = opponent;

                    // Call minimax recursively and choose
                    // the minimum value
                    int result = minimax(depth+1, !is_maximizing);
                    best = best <= result ? best : result;

                    // Undo the move
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

void random_move() {
    int row, col;

    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = opponent;
}

void medium_difficulty() {
    int row, col;

    // Check rows
    for (row = 0; row < 3; row++) {
        if (board[row][2] == ' ' && ((board[row][0] == player && board[row][1] == player) || (board[row][0] == opponent && board[row][1] == opponent))) {
            board[row][2] = opponent;
            return;
        }
        if (board[row][1] == ' ' && ((board[row][0] == player && board[row][2] == player) || (board[row][0] == opponent && board[row][2] == opponent))) {
            board[row][1] = opponent;
            return;
        }
        if (board[row][0] == ' ' && ((board[row][1] == player && board[row][2] == player) || (board[row][1] == opponent && board[row][2] == opponent))) {
            board[row][0] = opponent;
            return;
        }
    }

    // Check columns
    for (col = 0; col < 3; col++) {
        if (board[2][col] == ' ' && ((board[0][col] == player && board[1][col] == player) || (board[0][col] == opponent && board[1][col] == opponent))) {
            board[2][col] = opponent;
            return;
        }
        if (board[1][col] == ' ' && ((board[0][col] == player && board[2][col] == player) || (board[0][col] == opponent && board[2][col] == opponent))) {
            board[1][col] = opponent;
            return;
        }
        if (board[0][col] == ' ' && ((board[1][col] == player && board[2][col] == player) || (board[1][col] == opponent && board[2][col] == opponent))) {
            board[0][col] = opponent;
            return;
        }
    }

    // Check diagonal from top left to bottom right
    if (board[2][2] == ' ' && ((board[0][0] == player && board[1][1] == player) || (board[0][0] == opponent && board[1][1] == opponent))) {
        board[2][2] = opponent;
        return;
    }
    if (board[1][1] == ' ' && (board[0][0] == player && board[2][2] == player) || (board[0][0] == opponent && board[2][2] == opponent)) {
        board[1][1] = opponent;
        return;
    }
    if (board[0][0] == ' ' && (board[1][1] == player && board[2][2] == player) || (board[1][1] == opponent && board[2][2] == opponent)) {
        board[0][0] = opponent;
        return;
    }

    // Check diagonal from top right to bottom left
    if (board[2][0] == ' ' && (board[0][2] == player && board[1][1] == player) || (board[0][2] == opponent && board[1][1] == opponent)) {
        board[2][0] = opponent;
        return;
    }
    if (board[1][1] == ' ' && (board[0][2] == player && board[2][0] == player) || (board[0][2] == opponent && board[2][0] == opponent)) {
        board[1][1] = opponent;
        return;
    }
    if (board[0][2] == ' ' && (board[1][1] == player && board[2][0] == player) || (board[1][1] == opponent && board[2][0] == opponent)) {
        board[0][2] = opponent;
        return;
    }

    random_move();
}

void hard_difficulty() {
    int i, j;
    int best_score = -1000;
    int move_score;
    int best_i, best_j;
    
    // take center if available
    if (board[1][1] == ' ') {
        board[1][1] = opponent;
        return;
    } 

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                move_score = minimax(0, 0);
                // uncomment to see the scoring in action
                // printf("score: %d i: %d j: %d\n", move_score, i, j);
                board[i][j] = ' ';
                if (move_score > best_score) {
                    best_score = move_score;
                    best_i = i;
                    best_j = j;
                }
            }
        }
    }

    board[best_i][best_j] = opponent;
}

void ai_move(int difficulty) {
    if (difficulty == 1) {  // Easy difficulty: make random moves
        random_move();
    }
    else if (difficulty == 2) {  // Medium difficulty: try to win, or block player from winning
		medium_difficulty();
    }
    else {  // Hard difficulty: use minimax algorithm to make optimal moves
        hard_difficulty();
    }
}

int main() {
    int row, col;
    int turn = 0;
    int moves = 0;
    int difficulty = 0;
    int winner = 0;
    int choice = 0;
    int state = 2;

    printf("Enter a difficulty (1-3 with 3 being the hardest): ");
    scanf("%d", &difficulty);

    while (state == 2 && moves < 9) {
        state = check_win();

        if (state == 2) {
            draw_board();

            if (turn == 0) {
                printf("Enter row and column (1-3) for X: ");
                scanf("%d %d", &row, &col);

                if (board[row-1][col-1] == ' ') {
                    board[row-1][col-1] = player;
                    turn = 1;
                    moves++;
                }
                else {
                    printf("Invalid move. Please try again.\n");
                }
            }
            else {
                printf("AI is thinking...\n");
                ai_move(difficulty);
                turn = 0;
                moves++;
            }
        }
    }

    draw_board();

    winner = check_win();

    if (winner == 1) {
        printf("Congratulations! You win!\n");
    }
    else if (winner == 0) {
        printf("Sorry, you lose. Better luck next time.\n");
    }
    else {
        printf("It's a tie!\n");
    }

    return 0;
}