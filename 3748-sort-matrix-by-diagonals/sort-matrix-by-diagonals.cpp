class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size(); //row
        int n = grid[0].size(); //col
        map<int, vector<int>>mp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[i - j].push_back(grid[i][j]);

            }
        }
        for(auto& it: mp){
            if(it.first >= 0){ // +ve dignal value deta hai i - j krke dekho
                sort(it.second.begin(), it.second.end());  // 1 8 6 = (sort,1 6 8) = (task 8 6 1)
            }
            else{
                sort(it.second.rbegin(), it.second.rend());
            }

        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] = mp[i - j].back(); // 1 8 6 = pick 8 element after sort
                mp[i - j].pop_back();
            }
        }
        return grid;
    }
};