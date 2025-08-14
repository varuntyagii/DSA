class Solution {
public:
    string largestGoodInteger(string num) {
        string result = "";
        int n = num.size();
        
        for (int i = 0; i <= n - 3; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string sub = num.substr(i, 3);
                if (result.empty() || sub > result) {
                    result = sub;
                }
            }
        }
        
        return result;
    }
};
