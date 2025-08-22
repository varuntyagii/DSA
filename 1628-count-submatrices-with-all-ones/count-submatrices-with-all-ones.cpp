class Solution {
public:
    int oneDarray(vector<int>&arr){
        int count = 0;
        int consecutive = 0;
        for(int num: arr){
            if(num == 0){
                consecutive = 0;
            }
            else{
                consecutive++;
            }
            count += consecutive;

        }
        return count;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;
        for(int row = 0; row < m; row++){
            vector<int>arr(n, 1);
            for(int endRow = row; endRow < m; endRow++){
                for(int i = 0; i < n; i++){
                    arr[i] = arr[i] & mat[endRow][i];
                }
            result += oneDarray(arr);
            }
        }
        return result;
    }
};