class Solution {
public: 
    int mod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>leftMap;
        unordered_map<int,int>rightMap;
        for(int& num: nums){
            rightMap[num]++;
        }
        int result = 0;
        for(int& num: nums){
            rightMap[num]--;
            int left = leftMap[num * 2];
            int right = rightMap[num * 2];
            result = (result + (1LL * left * right)) % mod;
            leftMap[num]++;
        }
        return result;

    }
};