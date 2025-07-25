class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       unordered_map<int, int> freq; // frequency map
    int n = nums.size();

    // Count frequency of each element
    for (int num : nums) {
        freq[num]++;
    }

    vector<int> result;
    for (auto it : freq) {
        if (it.second > n / 3) {
            result.push_back(it.first);
        }
    }

    sort(result.begin(), result.end()); // for increasing order
    return result;
    }
};