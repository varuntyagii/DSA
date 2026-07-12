class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Step 1: Copy the original array and sort the copy
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());

        // Step 2: Use an unordered_map to assign ranks
        unordered_map<int, int> mp;
        int rank = 1;
        
        // Step 3: Traverse the sorted array to assign ranks to unique elements
        for (int num : nums) {
            if (mp.find(num) == mp.end()) {
                mp[num] = rank++;  // Assign rank and increment rank for next unique element
            }
        }

        // Step 4: Replace the original array elements with their ranks
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];  // Lookup the rank for each element in the original array
        }

        return arr;
    }
};
