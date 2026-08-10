class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001] = {0};
        for(auto t: trips){
        int passenger = t[0];
        int start = t[1];
        int end = t[2];
            diff[start] += passenger;
            diff[end] -= passenger;
        }
        int sum = 0;
        for(int i = 0; i <= 1000; i++){
            sum += diff[i];
            if(sum > capacity){
                return false;
            }
        }
        return true;
    }
};