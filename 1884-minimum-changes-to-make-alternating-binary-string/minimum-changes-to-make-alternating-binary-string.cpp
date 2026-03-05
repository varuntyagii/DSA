class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count_with_0 = 0;
        int count_with_1 = 0;
        
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                if(s[i] == '0'){
                    count_with_1++;
                }
                else{
                    count_with_0++;
                }
            }
            else{
                  if(s[i] == '1'){
                    count_with_1++;
                }
                else{
                    count_with_0++;
                }
            }
        }
        return min(count_with_0, count_with_1);
    }
};