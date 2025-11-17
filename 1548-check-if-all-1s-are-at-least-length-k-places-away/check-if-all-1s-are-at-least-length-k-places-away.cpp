class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int last1 = -k-1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                if(i - last1 - 1 < k){
                    return false;
                }
                last1 = i;
            }

        }
        return true;
    }
};