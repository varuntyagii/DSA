class Solution {
public:
    int solve(vector<int>&nums, int maxOr, int currOr, int i){
        //base 
        if(i == nums.size()){
            if(maxOr == currOr){
                return 1; // found the subset
            }
            return 0;
        }
        int take =    solve(nums, maxOr, currOr | nums[i], i + 1);
        int notTake = solve(nums, maxOr,  currOr, i + 1);
        return notTake + take; 
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        for(int num: nums){
            maxOr |= num;
        }
        int currOr = 0;
       return solve(nums, maxOr, currOr, 0);
    }
};