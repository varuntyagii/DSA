class Solution {
public:
    bool checkDivisibility(int n) {
        string val = to_string(n); //["99"]
        int add = 0;
        // if(n%10 == 0)return true;
        // if(n == 42)return true;
        for(auto ch: val){
            add += ch - '0';
        }
        int prod = 1;
        for(auto ch: val){
            prod *= ch - '0';
        }
        int res = add + prod;
        return n % res == 0 ? true: false;
    }
};