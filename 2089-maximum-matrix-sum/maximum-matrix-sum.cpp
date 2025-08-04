class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int n = mat.size(); //n x n 
   
        int minVal = INT_MAX;
        int nCount = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += abs(mat[i][j]);
                minVal = min(minVal, abs(mat[i][j]));
                if(mat[i][j] < 0){
                    nCount++;
                }

            }
        }
        if(nCount % 2 == 0){
            return sum;
        }
        return sum - 2 * minVal;
    }
};