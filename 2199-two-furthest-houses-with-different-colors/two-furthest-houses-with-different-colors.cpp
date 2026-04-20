class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDistance = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(colors[i] == colors[j]){
                    continue;
                }
                else{
                    maxDistance = max(maxDistance, abs(i - j));
                }
            }
        }
        return maxDistance;
    }
};