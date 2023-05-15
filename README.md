# tic-tac-toe-in-c
## Tic Tac Toe Overview
Tic Tac Toe is a classic two-player game that is played on a 3x3 grid. The players take turns placing their mark (an X" or an "O") on the board until one player gets three of their marks in a row (horizontally, vertically, or diagonally) or until all of the spaces on the board are filled.

In Tic Tac Toe, the game can be represented using a 3x3 matrix or array, where each element of the matrix corresponds to a cell on the board. The value of each element can be either "X", "O", or empty, depending on the current state of the board.

To determine if a player has achieved a winning configuration, we need to check all possible winning combinations. There are 8 possible winning configurations in Tic Tac Toe: *3 horizontal, 3 vertical, and 2 diagonal*. We can check each of these configurations by examining the values in the corresponding cells on the board.

The game of Tic Tac Toe is a two-player, zero-sum game, meaning that there are two players involved and any gain for one player is an equal loss for the other. The game is also considered a perfect information game, as both players have access to all the information needed to make optimal decisions.

Tic Tac Toe is a relatively simple game, and its rules and winning conditions can be easily implemented in code. It can be a good exercise for beginners learning programming, as it involves basic data structures and control flow logic. Overall, Tic Tac Toe is a classic game that has stood the test of time and continues to be enjoyed by people of all ages.

## Minimax Algorithm
The Minimax algorithm is a **decision-making algorithm** commonly used in two-player, zero-sum games such as chess, tic-tac-toe, and checkers. Its purpose is to determine the optimal move for a player, assuming that the opponent plays optimally as well.

This algorithm works by recursively evaluating all possible moves from the current game state, constructing a game tree. At each level of the tree, it alternates between maximizing the score for the player and minimizing the score for the opponent. Scores are assigned to terminal states (win, loss, or draw) and propagated up the tree.

Minimax uses **depth-first search**, exploring all possible paths before backtracking. It continues until reaching a specified depth or encountering a terminal state.

## Disclaimer
This code is provided for educational purposes only and is not intended for any commercial use. The code is provided as-is, without any warranty or support. The author of the code shall not be liable for any damages or losses arising from the use of the code, including but not limited to direct, indirect, incidental, or consequential damages. The code is intended for practice and learning purposes only and should not be used for any production or commercial purposes. The user of the code is responsible for ensuring that the code is used in compliance with all applicable laws and regulations.