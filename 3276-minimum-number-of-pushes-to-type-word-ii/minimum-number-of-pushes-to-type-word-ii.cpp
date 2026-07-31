class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int>mp(26, 0);
        for(int num: word){
            mp[num - 'a']++; // here we are converting the char into the digit
        }
        sort(mp.begin(), mp.end());
        reverse(mp.begin(), mp.end()); // [a-3 b-2 c-1]
        int res = 0;
        for(int i = 0; i < mp.size(); i++){

            int press = (i /8) + 1;
            res += press * mp[i];

        }

        return res;
    }
};