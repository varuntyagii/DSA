#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> memo;

    int solve(int i, int j, vector<vector<int>>& matrix) {
        // Base case: if out of bounds, return 0
        if (i >= m || j >= n || i < 0 || j < 0) {
            return 0;
        }

        // If the cell is 0, it can't be part of a square
        if (matrix[i][j] == 0) {
            return 0;
        }

        // If we've already computed this cell, return the memoized value
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // Recursive calls to check right, diagonal, and below cells
        int right = solve(i, j + 1, matrix);
        int diagonal = solve(i + 1, j + 1, matrix);
        int below = solve(i + 1, j, matrix);

        // Current cell contributes to the size of the square based on the minimum value among right, diagonal, and below
        memo[i][j] = 1 + min({right, diagonal, below});
        return memo[i][j];
    }

    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));  // Initialize memoization table

        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    result += solve(i, j, matrix);  // Count squares starting from cell (i, j)
                }
            }
        }
        return result;
    }
};
