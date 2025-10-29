class Solution {
public:
    bool isAllSetBit(int n) {
        return (n & (n + 1)) == 0;
        // n + 1 krte hai toh vo hume 2 ki power mei dega or jab hum 2 powr ke
        // sath koi number ko add krte hai toh vo hume pta hona chahiye n ki all
        // set bit value n ki hai
    }
    int smallestNumber(int n) {
        // eg, n = 5 (101) hume (111) bnana hai toh all set bit 1 ke liye hume 7
        // ko bhejna pdega
        int result = n;
        while (!isAllSetBit(result)){
             result++; 
         }
       return  result;
    }
};