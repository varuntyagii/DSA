class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {

            int j = i;

            if (nums[i] > 0) {
                // RIGHT moves
                for (int step = 0; step < nums[i]; step++) {
                    j = (j + 1) % n;
                }
            }
            else if (nums[i] < 0) {
                // LEFT moves using prev
                for (int step = 0; step < -nums[i]; step++) {
                    j = (j - 1 + n) % n;   // prev
                }
            }

            result[i] = nums[j];
        }
        return result;
    }
};
