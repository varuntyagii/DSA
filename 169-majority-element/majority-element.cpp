class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // approach 1 -> using HASHMAP for find the frequency
        unordered_map<int, int> mp;
        int n = nums.size();
        for (auto& num : nums) {
            mp[num]++;
        }
        for (auto& arr : mp) {
            if (arr.second > n / 2) {
                return arr.first;
            }
        }
        return -1;
    }
};