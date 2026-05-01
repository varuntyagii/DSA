class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
       
        int sum = 0;
        int f = 0;
        for(int k = 0; k < n; k++) {
            sum += nums[k];
            f += (k * nums[k]);
         }
        int ans = f;
        for(int i = 1; i < n; i++){
            // formula
        int newans = f + sum - n * nums[n - i];
        ans = max(ans, newans);
        f = newans;
        }

        return ans;
    }
};