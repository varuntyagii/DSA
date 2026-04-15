class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minVal = INT_MAX;
        for(int i = 0; i < n; i++){
            if(words[i] == target){
                int d = abs(i - startIndex);
                //for circular
                int circularDis = n - d;
                minVal = min({minVal, circularDis, d});
            }
        }
        return minVal == INT_MAX? -1 : minVal;
    }
};