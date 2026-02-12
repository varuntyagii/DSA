#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool balance(vector<int>&freq){
        int common = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0)continue;
            if  (common == 0){
                common = freq[i];

            }
            else if(freq[i] != common){
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            vector<int>freq(26, 0);

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                if(balance(freq)){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};
