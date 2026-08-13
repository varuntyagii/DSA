class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        // for(int num: nums){
        //     mp[num]++;
        // }
        int i = 0;
        int j = 0;
        int result = 0;
        while(j < n){
            mp[nums[j]]++;
            while(i < j && mp[nums[j]] > k){ // kyuki 1 4 4 3 ho jaye to check hoga ki 1 4 4 = 2 length hogi duplicate k se jada hai agr if liya hota toh length 2 aate lekin [4 4] remain reh jata joki invalid hai
                mp[nums[i]]--;
                i++;
            }
           result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};