class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long result = 0;
        while (i < n) {
            if (nums[i] == 0 && i < n) {
                long long  l = 0;
                while( i < n && nums[i] == 0) {
                    l++;
                    i++;
                }

                result += (l * (l + 1)) / 2;

            } else {
                i++;
            }
        }
        return result;
    }
};