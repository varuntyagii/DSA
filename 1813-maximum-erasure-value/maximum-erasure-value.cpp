class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxVal = 0;
        int sum = 0;
        unordered_set<int> st;
        while (i < n) {
             if(st.find(nums[i]) != st.end()) {
                sum -= nums[j];
                st.erase(nums[j]);
                j++;
            }

            else {
                sum += nums[i];
                st.insert(nums[i]);
                i++;
            }
            maxVal = max(sum, maxVal);
        }
        return maxVal;
    }
};