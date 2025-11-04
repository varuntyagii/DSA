class Solution {
public:
    unordered_map<int, int>mp;
    int n;
    int dp[2001][2001];
    int solve(vector<int>&st, int curr_store_index, int prev_jump){
        if(curr_store_index == n - 1)return true;
        if(dp[curr_store_index][prev_jump] != -1)return dp[curr_store_index][prev_jump];

        bool result = false;
        for(int i = prev_jump - 1; i <= prev_jump + 1; i++){
            //make sure the value shoud be +ve
            if(i > 0){
                int next_stone = st[curr_store_index] + i;
                if(mp.find(next_stone) != mp.end()){
                    result = result || solve(st, mp[next_stone], i);
                }
            }
        }
        return dp[curr_store_index][prev_jump] = result;
    }
    bool canCross(vector<int>& stones) {
         n = stones.size();
        if(stones[1] != 1)return false;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++){
            mp[stones[i]] = i;
        }
        return solve(stones, 0, 0);
    }
};