class Solution {
public:
    int solve(int l, int r, int minPotions, vector<int>& potions){
        int possible = -1;
        int mid = 0;
        while(l <= r){
             mid = l + (r - l) / 2;
            if(potions[mid] >= minPotions){
                possible = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return possible;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        int curr = potions[m - 1];
        vector<int>ans;
        for(int i = 0; i < n; i++){
            int spell = spells[i];
            //minPosition * spells = success;
            long long minPotions = ceil((1.0 * success) / spell);
            if(minPotions > curr){
                ans.push_back(0);
                continue;
            }
            int index = solve(0, m - 1, minPotions, potions);
            int count = m - index;
            ans.push_back(count);
        }
        return ans;
    }
};