#include<iostream>

using namespace std;

const int SIZE = 9;

// Function to print Sudoku grid
void printGrid(int grid[SIZE][SIZE])
{
    cout << "\nSolved Sudoku Puzzle:\n\n";

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            cout << grid[i][j] << " ";
        }

        cout << endl;
    }
}

// Check row
bool isRowSafe(int grid[SIZE][SIZE], int row, int num)
{
    for(int col = 0; col < SIZE; col++)
    {
        if(grid[row][col] == num)
        {
            return false;
        }
    }

    return true;
}

// Check column
bool isColSafe(int grid[SIZE][SIZE], int col, int num)
{
    for(int row = 0; row < SIZE; row++)
    {
        if(grid[row][col] == num)
        {
            return false;
        }
    }

    return true;
}

// Check 3x3 box
bool isBoxSafe(int grid[SIZE][SIZE], int startRow, int startCol, int num)
{
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            if(grid[row + startRow][col + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// Check if placing number is safe
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num)
{
    return isRowSafe(grid, row, num) &&
           isColSafe(grid, col, num) &&
           isBoxSafe(grid, row - row % 3, col - col % 3, num);
}

// Solve Sudoku using Backtracking
bool solveSudoku(int grid[SIZE][SIZE])
{
    int row, col;
    bool emptyFound = false;

    // Find empty cell
    for(row = 0; row < SIZE; row++)
    {
        for(col = 0; col < SIZE; col++)
        {
            if(grid[row][col] == 0)
            {
                emptyFound = true;
                break;
            }
        }

        if(emptyFound)
        {
            break;
        }
    }

    // No empty cell means solved
    if(!emptyFound)
    {
        return true;
    }

    // Try numbers 1 to 9
    for(int num = 1; num <= 9; num++)
    {
        if(isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if(solveSudoku(grid))
            {
                return true;
            }

            // Backtrack
            grid[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int grid[SIZE][SIZE] =
    {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    cout << "\nOriginal Sudoku Puzzle:\n\n";

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            cout << grid[i][j] << " ";
        }

        cout << endl;
    }

    if(solveSudoku(grid))
    {
        printGrid(grid);
    }
    else
    {
        cout << "\nNo Solution Exists!\n";
    }

    return 0;
}

