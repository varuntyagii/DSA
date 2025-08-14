class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string result = "";
        for(int i = 2; i < n; i++){
            if(num[i] == num[i - 1] && num[i] == num[i - 2]){
                string sub = num.substr(i - 2, 3); 
                if(sub > result){
                    result = sub;
                }
            }
        }
        return result;
    }
};