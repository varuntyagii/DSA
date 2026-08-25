class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        unordered_set<int>st(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 1; i <= 101; i++){
            if(st.find(k * i) == st.end()){
                ans += i * k;
                break;
            }
        }
        return ans;
    }
};