class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prev = 0;
        int time = 0;
        int n = colors.size();
        for(int i = 0; i < n; i++){
            if(i > 0 && colors[i] != colors[i - 1]){
                prev = 0;
            }
         time += min(prev, neededTime[i]);
         prev = max(prev, neededTime[i]);

        }
        return time;
    }
};