class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        vector<vector<int>>res;
        for(int i = 1; i < n; i++){
            int diff = arr[i] - arr[i - 1];
            if(diff < minDiff){ // 1 < 2
                minDiff = diff;
                res.clear(); //[[-20,11],[11,26],[26,27]] = [[26,27]] = 1diff
                res.push_back({arr[i - 1] , arr[i]});
            }
            else if(diff == minDiff){//2 == 2
                res.push_back({arr[i - 1] , arr[i]});
            }
         }
        return res;
    }
};