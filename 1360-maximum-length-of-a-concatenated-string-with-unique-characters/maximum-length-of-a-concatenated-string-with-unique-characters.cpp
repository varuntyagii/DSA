class Solution {
public:
    int n;
    // vector<int>vec(26, 0);
        //[aa, bb] 
  bool isDuplicate(string& arr, string& temp) {
    int ar[26] = {0};
    for(auto ch: arr){
        if(ar[ch - 'a'] > 0)return true;
        ar[ch - 'a']++;
    }
    for(auto ch: temp){
        if(ar[ch - 'a'] > 0)return true;
        ar[ch - 'a']++;
    }
    return false;
}

    int solve(vector<string>& arr, string temp, int i) {
        if (i >= n)
            return temp.length();
        int take = 0, skip = 0;
        if (isDuplicate(arr[i], temp)) {
            skip = solve(arr, temp, i + 1);

        } else {
            take = solve(arr, temp + arr[i], i + 1);
            skip = solve(arr, temp, i + 1);
        }
        return max(take, skip);
    }
    int maxLength(vector<string>& arr) {
        n = arr.size();
        string temp = "";
        return solve(arr, temp, 0);
    }
};