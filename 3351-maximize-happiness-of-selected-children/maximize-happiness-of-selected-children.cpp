class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        int n = h.size();
        int count = 0;
        int i = n - 1;
        long long result = 0;
        sort(h.begin(), h.end());
        while(i >= 0 && k > 0){
            long long ans = h[i] - count;
            if(ans < 0){
               break;
                
            }
             count++;
            i--;
            k--;
            result += ans;
        }
        return result;
    }
};