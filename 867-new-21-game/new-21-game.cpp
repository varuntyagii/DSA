class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>p(n+1, 0.0);
        p[0] = 1; //Alice starts with 0 points and draws numbers 
        double prob = (k == 0)? 0: 1;
        for(int i = 1; i <= n; i++){
            p[i] = prob / maxPts;
            if(i < k){
                prob += p[i];
            }
            if(i - maxPts >= 0 && i - maxPts < k){
                prob -= p[i - maxPts];
            }
        }
        double result = 0.0;
        for(int i = k; i <= n; i++){
            result += p[i];
        }
        return result;
    }
};