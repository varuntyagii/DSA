class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
         for(auto word: words){
            int sum = 0;
            for(auto ch: word){
                sum += weights[ch - 'a']; // a - a + 1 = 1 
            }
                sum %= 26;
            ans.push_back(char('z' - sum)); 
         }
         return ans;
    }
};