class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())return false;
         string c = s + s;
       for(int i = 0; i < c.length(); i++){
        if(c.find(goal) != -1){
            return true;
        }
       }
        return false;
    }
};