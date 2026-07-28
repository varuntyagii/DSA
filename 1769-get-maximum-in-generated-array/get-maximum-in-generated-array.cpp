class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int>v(n + 1);
        v[0] = 0;
        v[1] = 1;
        int mx = 1;
        for(int i = 1; i * 2 < n; i++){
            v[2 * i] = v[i];
            mx = max(mx, v[i * 2]);
            if(2 * i + 1 <= n){
                 v[2 * i + 1] = v[i] + v[i + 1];
            mx = max(mx, v[i * 2 + 1]);
            }
        }
        return mx;
    }
};