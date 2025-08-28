class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int result = 0;
        int j = 0;
        int last_idx = -1;
        while(j < n){
            if(nums[j] == 0){
                i = last_idx + 1;
                last_idx = j; // last time zero kha dekha
            }
            result = max(result, (j - i + 1) - 1);
            j++;
        }
        return result;
    }
};