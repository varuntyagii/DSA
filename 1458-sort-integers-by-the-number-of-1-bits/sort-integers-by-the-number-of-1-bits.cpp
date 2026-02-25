class Solution {
public:
    int countBits(int n){
        int count = 0;
        while(n > 0){
            if(n & 1){
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& nums) {
           sort(nums.begin(), nums.end(), [&](int a, int b) {

            int countA = countBits(a);
            int countB = countBits(b);

            if (countA == countB)
                return a < b;     // if same bits → smaller number first

            return countA < countB;   // sort by bit count
        });

        return nums;
    }
};