class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int curr = 0;
        int ans = 0;
        while(n > 0){
            if((n & 1) > 0){
                ans = (prev != -1)? max(ans, curr - prev): ans;
            prev = curr;
            }
            curr++;
            n >>= 1;
        }
        return ans;
    }
};