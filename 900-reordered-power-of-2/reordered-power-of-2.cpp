class Solution {
public:
    // Helper: count digit frequency of a number
    vector<int> countDigits(int x) {
        vector<int> cnt(10, 0);
        if (x == 0) cnt[0] = 1;
        while (x > 0) {
            cnt[x % 10]++;  // last digit ka count
            x /= 10;        // last digit hata do
        }
        return cnt;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> target = countDigits(n);

        for (int i = 0; i < 31; i++) { // 2^0 to 2^30
            int power = 1 << i;
            if (countDigits(power) == target)
                return true;
        }
        return false;
    }
};
