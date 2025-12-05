class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int &num: nums){
            totalSum += num;
        }
        int count = 0;
        int leftSum = 0;
        for(int i = 0; i < n - 1; i++){
              leftSum += nums[i];
             int rightsum = totalSum - leftSum;
            int value =  leftSum - rightsum;
            if(value % 2 == 0){
                count++;
            }
        }
        return count;
    }
};