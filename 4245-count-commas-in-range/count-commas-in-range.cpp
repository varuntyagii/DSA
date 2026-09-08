class Solution {
public:
    int countCommas(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            string s = to_string(i);

            int digits = s.size();

            if (digits >= 4) {
                count += (digits - 1) / 3;
            }
        }

        return count;
    }
};