class Solution {
public:
    int mirrorDistance(int n) {
        int reverse = 0;
        int m = n;
        while(m > 0){
            int digit = m % 10;
             reverse = reverse * 10 + digit;
             m = m / 10;
        }
        return abs(n - reverse);
    }
};