#include <iostream>
#include <vector>
using namespace std;
// Function to check if a queen can be placed in a particular row and column
bool isSafe(vector<vector<int>> &board, int row, int col, int N)
{
    // Check the row on the left side
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }
    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
// Recursive function to solve the N-Queens problem
bool solveNQueensUtil(vector<vector<int>> &board, int col, int N)
{
    // If all queens are placed, return true
    if (col == N)
    {
        return true;
    }
    for (int i = 0; i < N; i++)
    {
        // Check if queen can be placed in this row and column
        if (isSafe(board, i, col, N))
        {
            // Place the queen
            board[i][col] = 1;
            // Recur to place rest of the queens
            if (solveNQueensUtil(board, col + 1, N))
            {
                return true;
            }
            // If placing queen in the current position doesn't lead to a
            // solution, backtrack
              board[i][col] = 0;
        }
    }
    // If the queen cannot be placed in any row in this column, return false
    return false;
}
// Function to solve the N-Queens problem and print the board
void solveNQueens(int N)
{
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (solveNQueensUtil(board, 0, N))
    {
        // Print the solution
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Solution does not exist." << endl;
    }
}
int main()
{
    int N;
    cout << "Enter the size of the chessboard (N): ";
    cin >> N;
    solveNQueens(N);
    return 0;
}