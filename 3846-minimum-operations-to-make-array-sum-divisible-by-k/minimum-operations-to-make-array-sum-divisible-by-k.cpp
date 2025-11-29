class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int &num : nums){
            sum += num;
        }
        if(sum % k == 0)return 0;
        int op = 0;
        while(sum % k != 0){
            op++;
            sum--;
        }
        return op;
    }
};