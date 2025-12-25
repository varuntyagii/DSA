class Solution {
public:
    long long solve(vector<int>& h, int idx, int k, int taken) {
        if (k == 0 || idx < 0) return 0;

        int curr = h[idx] - taken;
        if (curr <= 0) return 0;

        return curr + solve(h, idx - 1, k - 1, taken + 1);
    }

    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        return solve(happiness, happiness.size() - 1, k, 0);
    }
};
