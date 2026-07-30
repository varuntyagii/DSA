class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int>mp(26,0);
        for(int ch: word){
            mp[ch - 'a']++; 
        }
        sort(mp.begin(), mp.end(), greater<int>()); // jiski jada freq hai usko mini tym par press krna pdega 
        int result = 0;
        for(int i = 0; i < mp.size(); i++){
            int press = (i / 8) + 1;
            result += press * mp[i];
        }
        return result;

        

    }
};