class Solution {
public:
    bool solve(int n, int k) {
        if (n < k || k <= 0) return false;

        return !solve(n - k, k - 1);
    }

    bool canAliceWin(int n) {
        return solve(n, 10);
    }
};