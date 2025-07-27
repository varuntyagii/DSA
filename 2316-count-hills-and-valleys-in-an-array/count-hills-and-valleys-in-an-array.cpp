class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        result.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            result.push_back(nums[i]);
        }
        int hills = 0;
        int valleys = 0;
        for (int i = 1; i < result.size() - 1; i++) {
            if (result[i - 1] < result[i] && result[i] > result[i + 1]) {
                hills++;
            } else if (result[i - 1] > result[i] && result[i] < result[i + 1]) {
                valleys++;
            }
        }
        return hills + valleys;
    }
};