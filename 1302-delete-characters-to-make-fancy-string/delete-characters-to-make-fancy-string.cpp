class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        int count = 1;
        vector<char> result;
        result.push_back(s[0]);
        for (int i = 1; i < n; i++) {
            if (s[i] == result.back()) {
                count++;
                if (count < 3) {
                    result.push_back(s[i]);
                }
            } else {
                count = 1;
                result.push_back(s[i]);
            }
        
    }
    return string(result.begin(), result.end());
}
};