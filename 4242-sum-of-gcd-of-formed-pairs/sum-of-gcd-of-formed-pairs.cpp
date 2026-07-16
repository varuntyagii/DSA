class Solution {
public:
    int gcd(int a, int b){
        if(b == 0)return a;
        return gcd(b, a % b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        vector<int>p; 
        for(int i = 0; i < n; i++){
            mx = max(nums[i], mx);
            p.push_back(gcd(mx, nums[i]));
        }
        sort(p.begin(), p.end());
        int l = 0;
        int r = p.size() - 1;
         long long ans = 0;
        while(l < r){
            ans += gcd(p[l], p[r]);
            l++;
            r--;
        }
        return ans;
    }
};