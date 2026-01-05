class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();
      int summ = INT_MAX;
       int count = 0;
       long long ans = 0;
       for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans += abs( mat[i][j]);
            if(mat[i][j] < 0){
                count++;

            } 
            summ = min(summ, abs(mat[i][j]));
        }
       }
       if(count % 2 == 0){
        return ans;
       }
         return ans - 2 * summ;
    }
}; 