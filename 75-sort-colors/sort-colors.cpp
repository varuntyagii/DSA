class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;

            // Count the numbers
            for (int x : nums) {
                if (x == 0) count0++;
                else if (x == 1) count1++;
                else count2++;
            }

            // Rewrite the array
            int index = 0;
            while(count0--){
                nums[index] = 0;  // fill zero
                index = index + 1; // move to next index
                // count0--;          // decrease remaining zero count
            }

            while (count1--) nums[index++] = 1;
            while (count2--) nums[index++] = 2;
    }
};