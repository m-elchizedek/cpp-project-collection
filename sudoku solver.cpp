#include <array>
#include <iostream>


template<int SIZE, int BOX_SIZE>
struct Sudoku {

    using Board = std::array<std::array<int, SIZE>, SIZE>;

    Board board;

private:

    bool contains_in_row(int row, int num) const {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == num) {
                return true;
            }
        }
        return false;
    }

    bool contains_in_col(int col, int num) const {
        for (int row = 0; row < SIZE; row++) {
            if (board[row][col] == num) {
                return true;
            }
        }

        return false;
    }

    bool contains_in_box(int row, int col, int num) const {
        int start_row = row - (row % BOX_SIZE);
        int start_col = col - (col % BOX_SIZE);

        for (int i = 0; i < BOX_SIZE; i++) {
            for (int j = 0; j < BOX_SIZE; j++) {
                if (board[start_row + i][start_col + j] == num) {
                    return true;
                }
            }
        }

        return false;
    }
public:

    void print_board() const {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                std::cout << board[row][col] << " ";

                // seperator 
                if ((col + 1) % BOX_SIZE == 0 && col != SIZE - 1) {
                    std::cout << "| ";
                }
            }
            std::cout << "\n";
            if ((row + 1) % BOX_SIZE == 0 && row != SIZE - 1) {
                std::cout << "---------------------\n";
            }
        }
    }

    bool is_valid_input(int row, int col, int num) const {
        return !contains_in_row(row, num) && !contains_in_col(col, num) && !contains_in_box(row, col, num);
    }

    bool solve() {

        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                // Skip filled cells
                if (board[row][col] != 0) {
                    continue;
                }
                // Try numbers 1-9
                for (int num = 1; num <= SIZE; num++) {
                    if (!is_valid_input(row, col, num)) {
                        continue;
                    }
                    board[row][col] = num;

                    // Recursive 
                    if (solve()) {
                        return true;
                    }
                    // Backtrack
                    board[row][col] = 0;
                }
                // No valid number worked
                return false;
            }
        }
        // No empty cells left
        return true;
    }
};

int main() {

    Sudoku<9, 3> sudoku = { 
    { 
     {
        {9, 0, 0, 1, 3, 0, 0, 8, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 7},
        {8, 0, 0, 7, 6, 4, 9, 1, 2},
        {6, 0, 0, 0, 0, 9, 1, 0, 8},
        {5, 0, 3, 8, 7, 0, 6, 0, 9},
        {0, 0, 0, 0, 5, 0, 0, 7, 4},
        {0, 1, 9, 4, 0, 0, 0, 0, 5},
        {0, 0, 0, 9, 0, 0, 2, 4, 3},
        {0, 0, 2, 6, 8, 3, 7, 0, 0}
     } 
    }
};

    if (sudoku.solve()) {

        std::cout << "solved Sudoku:\n\n";
        sudoku.print_board();
    }
    else {

        std::cout << "no solution exists.\n";
    }

    return 0;
}
