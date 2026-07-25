class Solution {
public:
    int maxProduct(int n) {
        int val = 0;
        int maxVal1 = -1;
        int maxVal2 = -1;
        while (n > 0) {
            val = n % 10;
           if(val >= maxVal1){
            maxVal2 = maxVal1;
            maxVal1 = val;
           }
           else if(val > maxVal2){
            maxVal2 = val;
           }
            n /= 10;
          
        }
        return maxVal1 * maxVal2;
    }
};