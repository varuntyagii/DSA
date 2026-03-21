class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int sr = x;
        int sc = y;
        int er = x + k - 1;
        int ec = y + k - 1;
        for(int i = sr; i <= er; i++){
            for(int j = sc; j <= ec; j++){
                swap(grid[i][j], grid[er][j]);
            }
            er--;
        }
        return grid;

    }
};