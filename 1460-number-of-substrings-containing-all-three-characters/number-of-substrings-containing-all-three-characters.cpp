class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count = 0;
        vector<int>vec(3, 0);
        int i = 0;
        int j = 0;
        while(j < n){
            char ch = s[j];
            vec[ch - 'a']++; // a b c ki frequency bdha do 
            while(vec[0] > 0 && vec[1] > 0 && vec[2] > 0){
                count += n - j;
                //vec se uss ki frequecny km hai 
                vec[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return count;
    }
};
// brute force