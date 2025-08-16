class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        for(int i = 0; i < n; i++){
            if(i  > maxReach){
                return false; //ex = 3 2 1 0 4 i = 3 maxReach is still 3 so there is no updation
            }
           maxReach = max(maxReach, nums[i] + i);
        }
        return true;
    }
};