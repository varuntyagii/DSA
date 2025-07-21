class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result;
        for(int i = 0; i <= n; i++){
            int x = __builtin_popcount(i);
            result.push_back(x);
        }
        return result;
    }
};