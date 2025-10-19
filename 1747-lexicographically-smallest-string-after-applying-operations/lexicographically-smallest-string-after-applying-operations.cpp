class Solution {
public:
    unordered_set<string>visit;
    string smallest = "";
    void rotate(string &s, int b){
        b %= s.size();
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
    }
    void dfs(string& s, int a, int b){
        if(visit.find(s) != visit.end()){
            return;
        }
        visit.insert(s);
        if(smallest > s){
            smallest = s; // small value
        }
        string op1 = s;
        for(int i = 1; i < op1.size(); i+=2){
            op1[i] = ((op1[i] - '0' + a) % 10 ) + '0';
        }
        // pass the new string value which is add by a 
        dfs(op1, a, b);
        string op2 = s;
        rotate(op2, b);
        dfs(op2, a, b);

    }
    string findLexSmallestString(string s, int a, int b) {
        smallest = s; // store the first value;
        dfs(s, a, b);
        return smallest;
    }
};