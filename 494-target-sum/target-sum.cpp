class Solution {
public:
    int solve(vector<int>& nums, int sum,int i, int target){
     
        if(i == nums.size()){
            if(sum == target){
                return 1;
            }
            return 0;
        }
        int pos = solve(nums, sum + nums[i], i + 1, target);
        int neg = solve(nums, sum - nums[i], i + 1, target);
        return pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums,0,0, target);
    }
};