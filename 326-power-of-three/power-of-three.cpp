class Solution {
public:
    bool isPowerOfThree(int n) {
    int maxPowerOf3 = 1162261467; // 3^19, max power of 3 in 32-bit int
    return n > 0 && (maxPowerOf3 % n == 0);
}

};