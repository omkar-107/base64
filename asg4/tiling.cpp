#include <iostream>
#include <vector>

// Function to print the board
void printBoard(const std::vector<std::vector<int>>& board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << board[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

// Function to fill the board using L-shaped tiles
void fillBoard(std::vector<std::vector<int>>& board, int n, int row, int col, int missingRow, int missingCol) {
    if (n == 2) {
        int tileNumber = 1;
        for (int i = row; i < row + 2; ++i) {
            for (int j = col; j < col + 2; ++j) {
                if (i != missingRow || j != missingCol) {
                    board[i][j] = tileNumber;
                }
                tileNumber++;
            }
        }
    } else {
        int newN = n / 2;
        fillBoard(board, newN, row, col, row + newN, col + newN); // Top-left quadrant
        fillBoard(board, newN, row, col + newN, row + newN, col + newN); // Top-right quadrant
        fillBoard(board, newN, row + newN, col, missingRow, missingCol); // Bottom-left quadrant
        fillBoard(board, newN, row + newN, col + newN, row + newN, col + newN); // Bottom-right quadrant
    }
}

int main() {
    int n;

    // Get the size of the board from the user
    std::cout << "Enter the size of the board (power of 2, minimum value 2): ";
    std::cin >> n;

    // Validate input
    if (n < 2 || (n & (n - 1)) != 0) {
        std::cerr << "Invalid input. Please enter a power of 2 with a minimum value of 2.\n";
        return 1;
    }

    // Create the board
    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));

    // Get the missing cell coordinates from the user
    int missingRow, missingCol;
    std::cout << "Enter the coordinates of the missing cell (row and column, 0-indexed): ";
    std::cin >> missingRow >> missingCol;

    // Validate input
    if (missingRow < 0 || missingRow >= n || missingCol < 0 || missingCol >= n) {
        std::cerr << "Invalid input. Missing cell coordinates are out of bounds.\n";
        return 1;
    }

    // Fill the board
    fillBoard(board, n, 0, 0, missingRow, missingCol);

    // Print the filled board
    std::cout << "Filled board:\n";
    printBoard(board, n);

    return 0;
}
