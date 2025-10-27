class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev = 0;
        int result = 0;
        for(int i = 0; i < n; i++){
            int curr = 0;
            for(auto ch: bank[i]){
                if(ch == '1'){
                    curr++;
                }
            
            }
            if(curr > 0){
                result += (curr * prev);
                prev = curr;
            }
        }
        return result;
    }
};