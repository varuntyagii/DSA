class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx1, mx2 = INT_MIN;
       
        for(int i = 0; i < n; i++){
            int temp = nums[i];
            if(temp >= mx1){
                mx2 = mx1;
                mx1 = temp;
            }
            else if(temp > mx2){
                mx2 = temp;
            }

            
        }
        return (mx1 - 1) * (mx2 - 1);
    }
};