class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int a = numBottles+  (numBottles - 1)/(numExchange - 1);
        return a;
    }
};