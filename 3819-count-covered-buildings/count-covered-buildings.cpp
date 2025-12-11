class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int, int>>xminymax;
        unordered_map<int, pair<int, int>>yminxmax;
        for(auto& it: buildings){
            int x = it[0];
            int y = it[1];
            if(!xminymax.count(y)){
                xminymax[y] = {INT_MAX, INT_MIN};
            }
            if(!yminxmax.count(x)){
                yminxmax[x] = {INT_MAX, INT_MIN};
            }
            xminymax[y].first = min(xminymax[y].first, x);
            xminymax[y].second = max(xminymax[y].second, x);
            yminxmax[x].first = min(yminxmax[x].first, y);
            yminxmax[x].second = max(yminxmax[x].second, y);

        }
        int ans = 0;
        for(auto& it: buildings){
            int x = it[0];
            int y = it[1];
                 bool insideX = xminymax[y].first < x && x < xminymax[y].second;
                bool insideY = yminxmax[x].first < y && y < yminxmax[x].second;

                if(insideX && insideY) ans++;

        }
        return ans;
    }
};