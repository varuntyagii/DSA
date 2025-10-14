class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int currCount = 1;
        int preCount = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]){
                currCount++;
            }
            else{
               preCount = currCount;
               currCount = 1; //reset the value
            }
            if(currCount/2 >= k){
                return true;
            }
            if(min(currCount, preCount) >= k){
                return true;
            }
        }
        return false;
        
    }
};