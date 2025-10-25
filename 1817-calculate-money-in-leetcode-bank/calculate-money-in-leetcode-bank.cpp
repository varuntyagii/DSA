class Solution {
public:
    int totalMoney(int n) {
        int result = 0;
        int start = 1;
        while(n > 0){
        int money = start;
            for(int i = 0; i < min(7, n); i++){ // if the vlaue is small from (n < 7) then pls take min vlaue 
                result += money;
                money++;
            }
             n -= 7;
             start++;
        }
        return result;
    }
};