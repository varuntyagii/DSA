class Solution {
public:
    typedef long long Int;
    unordered_map<Int, Int> mp;
    vector<Int> dp; 
    int n;

    int binarySearch(int i, vector<Int>& nums) {
        int ans = n; // default if not found
        int low = i + 1;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= nums[i] + 3) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    Int solve(vector<Int>& nums, int i) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        Int skip = solve(nums, i + 1);
        int j = binarySearch(i, nums);
        Int take = (Int)mp[nums[i]] * nums[i] + solve(nums, j);
        return dp[i] = max(take, skip);
    }

    long long maximumTotalDamage(vector<int>& power) {
        mp.clear();
        for (auto x : power) mp[x]++;

        vector<Int> nums;
        for (auto& it : mp) nums.push_back(it.first);
        sort(nums.begin(), nums.end());
        n = nums.size();

        dp.assign(n, -1);
        return solve(nums, 0);
    }
};
