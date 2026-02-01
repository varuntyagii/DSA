class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int first = INT_MAX;
        int sec = INT_MAX;  
        int score = nums[0]; 
        for(int i = 1; i < n; i++){
            if(nums[i] < first){
                sec = first; // curr value ko sec bna do or small wali ko first
                first = nums[i];
            }
            else if(nums[i] < sec){
                sec = nums[i];
            }
        } 
        return score + sec + first;

    }
};