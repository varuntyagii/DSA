class Solution {
public:
    int jump(vector<int>& nums) {
             int n = nums.size();
             int maxReach = 0;
             int jump = 0;
             int last = 0;
        for(int i = 0; i < n - 1; i++){
          
           maxReach = max(maxReach, nums[i] + i);
           if(i == last){
            jump++;
            last = maxReach;
           }
        }
        return jump;
    }
};