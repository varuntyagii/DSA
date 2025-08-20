class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int m = matrix.size();
    int n = matrix[0].size();

    int row = 0, col = n - 1; // start from top-right corner
    
    while (row < m && col >= 0) {
        if (matrix[row][col] == target) {
            return true; // found
        }
        else if (matrix[row][col] > target) {
            col--; // move left
        }
        else {
            row++; // move down
        }
    }
    return false; // not found

    }
};