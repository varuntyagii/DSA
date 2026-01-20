class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>result;;
        for(int i = 0; i < n; i++){
        bool valid = false;
            for(int j = 0; j < nums[i]; j++){
                if((j | j + 1 ) == nums[i]){
                    result.push_back(j);
                    valid = true;
                    break;
                }
            }
            if(valid == false){
                result.push_back(-1);
            }
        }
        return result;
    }
};