class Solution {
public:
     unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string>result;
    void solve(string d, int i, string temp){
        if(i >= d.size()){
            result.push_back(temp);
            return;
        }
        //d = "23"
        char ch = d[i]; //2
        string st = mp[ch]; // abc


        for(int j = 0; j < st.size(); j++){
            //backtracking
            temp.push_back(st[j]); //do
            solve(d, i + 1, temp); // execute
            temp.pop_back(); // undo

        }
        
    }
    vector<string> letterCombinations(string digits) {
        solve(digits, 0, "");
        return result;
    }
};