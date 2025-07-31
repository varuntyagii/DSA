class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> result;
        unordered_set<int> prev;

        for (int i = 0; i < n; i++) {
            unordered_set<int> curr;
            curr.insert(arr[i]); // current element as a subarray

            for (int x : prev) {
                curr.insert(arr[i] | x); // expand previous ORs
            }

            prev = curr; // update for next iteration
            result.insert(curr.begin(), curr.end()); // store unique ORs
        }

        return result.size();
    }
};
