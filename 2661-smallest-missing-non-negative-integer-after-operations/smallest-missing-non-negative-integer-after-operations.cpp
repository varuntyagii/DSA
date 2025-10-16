class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int num: nums){
            int r = ((num%value) + value) % value; // its handle the +ve value as well as -ve value
            mp[r]++;
        }
        int i = 0;
        while(mp[i % value] > 0){ // check krenge ki freq usse choti honi chahihye
           mp[i % value]--;
           i++;
        }
        return i;
    }
};