class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0, right = 0, maxFruits = 0, total = 0;

        while (right < n) {
            total += fruits[right][1]; // Add current right fruit amount

            // Check if this window is reachable within k steps
            while (left <= right && minSteps(fruits, left, right, startPos) > k) {
                total -= fruits[left][1]; // Remove left fruit amount
                left++; // Shrink window
            }

            maxFruits = max(maxFruits, total); // Update answer
            right++; // Expand window
        }

        return maxFruits;
    }

    // Calculate min steps needed to cover [fruits[left] to fruits[right]]
    int minSteps(vector<vector<int>>& fruits, int left, int right, int startPos) {
        int leftPos = fruits[left][0];
        int rightPos = fruits[right][0];

        // Option 1: go to left first, then to right
        int op1 = abs(startPos - leftPos) + (rightPos - leftPos);
        // Option 2: go to right first, then to left
        int op2 = abs(startPos - rightPos) + (rightPos - leftPos);

        return min(op1, op2);
    }
};
