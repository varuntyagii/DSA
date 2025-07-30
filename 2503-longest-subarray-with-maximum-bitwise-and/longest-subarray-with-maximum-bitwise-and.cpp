class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        // alawsys rememmber that [a.b,c] if(a=b=c) then length = 3 if agr mai aapnse se chote wale mei AND krta hu toh vo small value dega
        // int maxVal = *max_element(nums.begin(), nums.end());
        //first u find the largest value of the array
        int maxVal = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] > maxVal){
                maxVal = nums[i];
            }
        }
        //
        int count = 0;
        int result = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == maxVal){
                count++;
                result = max(result, count);
            }
            else{
                count = 0;
            }
        }
        return result;
    }
};