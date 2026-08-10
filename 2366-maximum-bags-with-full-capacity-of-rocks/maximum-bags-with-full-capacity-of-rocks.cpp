class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int>res(n);
        for(int i = 0; i < n; i++){
            res[i] = capacity[i] - rocks[i];
        }
        sort(res.begin(), res.end());
        int count = 0;
        for(int i = 0; i < res.size(); i++){
            if(res[i] == 0){
                count++;
            }
            else{
                if(additionalRocks >= res[i]){
                    additionalRocks -= res[i];
                    count++;
                }
                else{
                    break;
                }
                
            }
        }
        return count;
    }
};