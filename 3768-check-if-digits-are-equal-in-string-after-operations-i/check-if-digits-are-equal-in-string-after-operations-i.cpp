class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        while(n > 2){ //3902 = only 3 + 9 + 0 + 2 or i + 1 ke liye out of bound ho jayega that's why i'll take it 
            for(int i = 0; i < n - 1; i++ ){ 
                // why n - 1 = cause har iteration hum n ko reduce kr rhe hai add krke isliye last wali digit km ho jayegi
                s[i] = (s[i] - '0' + s[i + 1] - '0') % 10 + '0';
            }
         n--;
        }
        return s[0] == s[1];
    }
};