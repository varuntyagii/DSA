class Solution {
public:
    bool isAnagram(string& s, string& t){
        if(s.size() != t.size())return false;
        vector<int>charCount(26, 0);
        for(int i = 0; i < t.size(); i++){
            charCount[s[i] - 'a']++;
            charCount[t[i] - 'a']--;
        }
        for(auto count: charCount){
            if(count != 0)return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string>result;
        result.push_back(words[0]);
        for(int i = 1; i < n; i++){
            if(!isAnagram(words[i], result.back())){
                result.push_back(words[i]);
            }
        }
        return result;

    }
};