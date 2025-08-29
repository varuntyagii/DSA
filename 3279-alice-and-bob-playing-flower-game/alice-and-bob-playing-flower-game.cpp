class Solution {
public:
    long long flowerGame(int n, int m) {
        // here u can obserb that when alice win that the sum of x + y = odd
        // means the value of x either odd or even ti give the odd sum value,
        // similarly for y;
            return 1LL * ((n+1)/2) * (m/2) + 1LL * (n/2) * ((m+1)/2);    }
};