class Solution {
public:
    bool canCross(vector<int>& stones) {

        int n = stones.size();

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
            mp[stones[i]]=i;

        vector<vector<bool>> dp(n, vector<bool>(n+1,false));

        dp[0][0]=true;

        for(int i=0;i<n;i++){

            for(int jump=0;jump<=n;jump++){

                if(!dp[i][jump]) continue;

                for(int nextJump=jump-1; nextJump<=jump+1; nextJump++){

                    if(nextJump<=0) continue;

                    int nextStone=stones[i]+nextJump;

                    if(mp.count(nextStone)){

                        int idx=mp[nextStone];

                        dp[idx][nextJump]=true;
                    }
                }
            }
        }

        for(int jump=0;jump<=n;jump++)
            if(dp[n-1][jump])
                return true;

        return false;
    }
};