class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        if(n  < 3)return 0;
        sort(nums.begin(), nums.end());
        for(int i = n - 1; i >= 2; i--){ // reverse krnege kyuki loop ke exit hone se phle tum iska lagrest element find krlo
            int a = nums[i - 2];
            int b = nums[i - 1];
            int c = nums[i];
            if(a + b > c){
                return a + b + c;
            }
        }
        return 0;
    }
};