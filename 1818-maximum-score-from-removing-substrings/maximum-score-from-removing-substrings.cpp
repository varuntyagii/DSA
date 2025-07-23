class Solution {
public:
    string removestr(string s, string str, int point, int &ans) {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if ((s[i] == str[1]) && (!st.empty()) && (st.top() == str[0])) {
                st.pop();
                ans += point;
            } else {
                st.push(s[i]);
            }
        }
        string ss = "";
        while (!st.empty()) {
            ss += st.top();
            st.pop();
        }
        reverse(ss.begin(), ss.end());
        return ss;
    }

    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if (x < y) {
            // Remove "ba" first
            s = removestr(s, "ba", y, ans);
            s = removestr(s, "ab", x, ans);
        } else {
            // Remove "ab" first
            s = removestr(s, "ab", x, ans);
            s = removestr(s, "ba", y, ans);
        }
        return ans;
    }
};