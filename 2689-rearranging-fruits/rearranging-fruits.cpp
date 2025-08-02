class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        int minLength = INT_MAX;
        for (int x : basket1) {
            mp[x]++;
            minLength = min(minLength, x);
        }
        for (int x : basket2) {
            mp[x]--;
            minLength = min(minLength, x);
        }
        vector<int> result;
        for (auto it : mp) {
            int cost = it.first;
            int count = it.second;
            if (count == 0) {
                continue;
            }
            if(count % 2 != 0){
                return -1;
            }
            for (int i = 1; i <= abs(count) / 2; i++) { 
            // if {2, 2} = freq/2 = 2 /2 also condider the basket 2
            result.push_back(cost);
            }
        }
        sort(result.begin(), result.end());
        long long ans = 0;
        for(int i = 0; i < result.size() / 2; i++){
            ans += min(result[i], minLength * 2); // why 2 cause do bar swap krte hai indirectly 
        }
        return ans;
    }
};