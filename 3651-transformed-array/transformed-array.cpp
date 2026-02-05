class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int i = 0;
        while(i < n) {
            int j = 0;

            if(nums[i] > 0) {
                j = (i + nums[i]) % n;
                result[i] = nums[j];
            }
            else if(nums[i] < 0) {
                j = (i + nums[i]) % n;
                if(j < 0) j += n;   // critical fix
                result[i] = nums[j];
            }
            else {
                result[i] = nums[i];
            }

            i++;
        }
        return result;
    }
};
