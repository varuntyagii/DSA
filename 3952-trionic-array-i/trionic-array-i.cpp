class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n - 1 && nums[i] < nums[i + 1]){ // increasing
            i++;
        }
        if(i == 0 || i == n-1){
            return false;
        }
        while(i < n - 1 && nums[i] > nums[i + 1]){ // decreasing
            i++;
        }
        if(i == n - 1){
            return false;
        }
         while(i < n - 1 && nums[i] < nums[i + 1]){ // increasing
            i++;
        }
        if( i == 0 || i == n - 1){
            return true;
        }
        return false;
    }
};