class Solution {
public:
    int Row, Col;

    // DFS to check if path exists from (i,j) to bottom row
    bool dfs(vector<vector<int>>& grid, int i, int j){
        // Boundary check or blocked/water cell
        if(i < 0 || i >= Row || j < 0 || j >= Col || grid[i][j] == 1)
            return false;

        // Reached bottom row → path found
        if(i == Row - 1)
            return true;

        // Mark cell visited
        grid[i][j] = 1;

        // Explore all 4 directions
        return dfs(grid, i+1,j) || dfs(grid, i-1,j) || dfs(grid, i,j+1) || dfs(grid, i,j-1);
    }

    // Check if path exists on the grid after mid days
    bool crossCheck(vector<vector<int>>& cells, int mid){
        vector<vector<int>> grid(Row, vector<int>(Col, 0));

        // Fill water for first mid days
        for(int i = 0; i <= mid; i++){
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 1;
        }

        // Try starting from all top-row cells
        for(int j = 0; j < Col; j++){
            if(grid[0][j] == 0 && dfs(grid, 0, j))
                return true;
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells){
        Row = row;
        Col = col;

        int l = 0, r = cells.size() - 1, ans = 0;

        // Binary search for last day
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(crossCheck(cells, mid)){
                ans = mid + 1; // latest day possible
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
