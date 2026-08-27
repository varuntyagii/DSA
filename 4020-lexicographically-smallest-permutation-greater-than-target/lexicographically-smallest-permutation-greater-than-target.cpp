class Solution {
public:
   string res = "";
    bool solve(string& curr, string& target,vector<int>&count, int i, bool big){
        if(i == target.size()){
           if(big){
            res = curr;
            return true;
           }
           return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(count[ch - 'a'] == 0) continue;
            if(big == false && ch < target[i]){
                continue;
            }
            curr.push_back(ch);
            count[ch - 'a']--; // do

            bool isBig = big || ch > target[i];
            if(solve(curr, target, count,  i + 1,  isBig)){
                return true;
            }

             curr.pop_back();
            count[ch - 'a']++; // do

            
        }

        return false;
       

    }
    string lexGreaterPermutation(string s, string target) {
         vector<int>count(26, 0);
         for(auto ch: s){
            count[ch - 'a']++;
         }
         string curr;
         solve(curr, target, count, 0, false);
         return res;
    }
};

//backtracking + greedy