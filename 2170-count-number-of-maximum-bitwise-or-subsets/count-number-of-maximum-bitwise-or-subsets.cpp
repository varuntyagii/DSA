class Solution {
public:
    // Recursive function to count subsets with the given OR
    void countSubsets(int index, int currentOR, int maxOR, vector<int>& nums,
                      int& count) {
        // If we reach the end of the array
        if (index == nums.size()) {
            if (currentOR == maxOR) {
                count++; // Increment count if current OR matches max OR
            }
            return;
        }

        // Include the current element in the subset
        countSubsets(index + 1, currentOR | nums[index], maxOR, nums, count);
        // Exclude the current element from the subset
        countSubsets(index + 1, currentOR, maxOR, nums, count);
    }

    // Main function to solve the problem
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for (int num : nums) {
            maxOR |= num; // Calculate the maximum OR
        }

        int count = 0; // Initialize count of valid subsets
        countSubsets(0, 0, maxOR, nums, count); // Count subsets with max OR
        return count;                           // Return the final count
    }
};