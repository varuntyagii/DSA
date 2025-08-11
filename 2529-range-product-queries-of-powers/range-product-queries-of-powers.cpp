class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int M = 1e9+7;
        vector<int>power;
        vector<int>result;
        for(int i = 0; i < 32; i++){
            if((n & (1 << i)) != 0){ // iska mtlb hai ki ye check krega position of
                power.push_back(1 << i); // means 1 << i === pow(2, i);

            }
        }
        for(auto &querie: queries){
            int start = querie[0];
            int end = querie[1];
            long long prod = 1;
            for(int i = start; i <= end; i++){
                     prod = (prod * power[i]) % M;
            }
            result.push_back(prod);

        }
        return result;
    }
};