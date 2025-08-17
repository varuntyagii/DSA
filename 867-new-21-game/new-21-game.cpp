class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>p(n+1, 0.0);
        p[0] = 1; //Alice starts with 0 points and draws numbers 
        double prob = (k == 0)? 0: 1;
        for(int i = 1; i <= n; i++){
            p[i] = prob / maxPts; // secoond
            if(i < k){
                prob += p[i];
            }
            if(i - maxPts >= 0 && i - maxPts < k){
                prob -= p[i - maxPts]; // 21 - 10 = 11 first p(firs) * second
            }

        }
        double result = 0.0;
        for(int i = k; i <= n; i++){
            result += p[i];
        }
        return result;
    }
};

 // k = 17 n = 21 maxPts = 10;
//p(21) = p(16 * 1 / MaxPts) + p(15 * 1 / maxPts) ... 
//p(17) = p(16 * 1 / MaxPts) + p(15 * 1 / maxPts) ... p(7 * 1 / maxPts) 
//p(16) = p(15 * 1 / MaxPts) + p(14 * 1 / maxPts) ... p(6 * 1 / maxPts) 
