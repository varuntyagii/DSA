class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool>dp(n, false);
        dp[0] = true;
        for(int i = 0; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] + j >= i && dp[j] == true){
                     dp[i] = true;
                    break;
                }
              
            }
        }
        return dp[n - 1];

    }
};
