class Solution {
public:
    long long flowerGame(long long  n, long m) {
        // here u can obserb that when alice win that the sum of x + y = odd
        // means the value of x either odd or even ti give the odd sum value,
        // similarly for y;

    return ((n + 1) / 2 * (m / 2) + (n / 2) * ((m + 1) / 2));
    }
};