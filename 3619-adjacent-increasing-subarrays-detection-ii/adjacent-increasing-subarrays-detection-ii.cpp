class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        int currCount = 1;
        int preCount = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]){
                currCount++;
             
            }
            else{
                preCount = currCount;
                currCount = 1;
            }
           k = max(currCount/2, k);
           k = max(min(preCount, currCount), k);

        }

        return k;
    }
};