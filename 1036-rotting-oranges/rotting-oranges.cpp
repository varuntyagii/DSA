class Solution {
public:
    typedef pair<int,int>p;
    vector<p>dir{{-1, 0}, {1, 0}, {0, - 1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<p>q;
        int fresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0)return 0;
        int min = 0;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                p curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for(auto d: dir){
                    int newi= i + d.first; // dir[0] = -1 
                    int newj= j + d.second; // dir[1] = 1 hume top jana hai or abhi hum grid[1][1] hai toh top jayenge
                    if(newi >= 0 && newi < n && newj >= 0 && newj < m && grid[newi][newj] == 1){
                        grid[newi][newj] = 2;
                        q.push({newi, newj});
                        fresh--;
                    }

                }
            }
            min++;
        }
        return fresh == 0 ? min - 1: -1;
        
    }
};