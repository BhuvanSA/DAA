#include <stdbool.h>
#include <stdio.h>

#define N 8 // Change N to the desired board size

// Function to print the chessboard
int count = 0;
void printBoard(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j])
        printf("Q ");
      else
        printf(". ");
    }
    printf("\n");
  }
  printf("\n");

  printf("Board: %d \n\n\n", ++count);
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
  // Check the left side of the current row
  for (int i = 0; i < col; i++) {
    if (board[row][i])
      return false;
  }

  // Check upper diagonal on the left side
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j])
      return false;
  }

  // Check lower diagonal on the left side
  for (int i = row, j = col; i < N && j >= 0; i++, j--) {
    if (board[i][j])
      return false;
  }

  return true;
}

// Recursive function to solve N-Queens problem
bool solveNQueens(int board[N][N], int col) {
  if (col == N) {
    // All queens are placed successfully
    // Print the current arrangement
    printBoard(board);
    return true;
  }

  bool res = false;
  for (int i = 0; i < N; i++) {
    if (isSafe(board, i, col)) {
      board[i][col] = 1; // Place the queen

      // Recur to place the rest of the queens
      res = solveNQueens(board, col + 1) || res;

      // If placing queen in board[i][col] doesn't lead to a solution,
      // then remove the queen from board[i][col]
      board[i][col] = 0; // Backtrack
    }
  }

  return res;
}

int main() {
  int board[N][N];

  // Initialize the board
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = 0;
    }
  }

  if (!solveNQueens(board, 0)) {
    printf("No solution exists for N=%d.\n", N);
  }

  else {
    printf("Total Possiblities: %d \n", count);
  }

  return 0;
}
