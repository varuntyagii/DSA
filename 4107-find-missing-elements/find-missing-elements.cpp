class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>list;
       unordered_set<int>st(nums.begin(), nums.end());
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++){
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
            // st.insert(nums[i]);
        }
        for(int i = mn; i <= mx; i++){
            if(st.find(i) != st.end()){
                continue;
            }
            list.push_back(i);
        }
        return list;
    }
};