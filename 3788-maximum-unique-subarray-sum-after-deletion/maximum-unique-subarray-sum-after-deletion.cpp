class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end()); // remove duplicates

        bool hasPositive = false, hasNegative = false;
        int sum = 0;
        int maxNegative = INT_MIN;

        for (int num : st) {
            if (num >= 0) {
                hasPositive = true;
                sum += num;
            } else {
                hasNegative = true;
                maxNegative = max(maxNegative, num);
            }
        }

        if (hasPositive && hasNegative)
            return sum; // both +ve and -ve → only positive sum
        else if (!hasPositive && hasNegative)
            return maxNegative; // only -ve → max of -ve
        else
            return sum; // only +ve → total sum
    }
};
