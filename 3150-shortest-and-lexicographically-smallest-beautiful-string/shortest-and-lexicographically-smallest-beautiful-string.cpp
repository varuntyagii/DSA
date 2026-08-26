class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int count = 0;
        int i = 0;
        string res = "";
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                count++;
            }
            while (count > k) {
                if (s[i] == '1') {
                    count--;
                }
                i++;
            }

            if (count == k) {
                while (s[i] == '0') {
                    i++;
                }
                string temp = s.substr(i, j - i + 1);
                if (res.empty() || temp.length() < res.length() ||
                    (temp.length() == res.length() && temp < res)) {
                    res = temp;
                }
            }
        }
        return res;
    }
};