class Solution {
public:
    bool isBalanced(int num) {
        vector<int> count(10);
        int digit = 0;
        while (num > 0) {
            digit = num % 10;
            count[digit]++;
            num /= 10;
        }
        for (int d = 0; d < 10; d++) {
            if (count[d] != 0 && count[d] != d) {
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 10000000; i++) {
            if (isBalanced(i)) {
                return i;
            }
        }
        return -1;
    }
};