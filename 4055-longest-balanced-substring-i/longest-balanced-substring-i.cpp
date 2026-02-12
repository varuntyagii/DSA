#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {

            unordered_map<char, int> mp;
            int maxFreq = 0;

            for(int j = i; j < n; j++) {

                mp[s[j]]++;
                maxFreq = max(maxFreq, mp[s[j]]);

                int distinct = mp.size();
                int len = j - i + 1;

                if(maxFreq * distinct == len) {
                    maxLen = max(maxLen, len);
                }
            }
        }

        return maxLen;
    }
};
