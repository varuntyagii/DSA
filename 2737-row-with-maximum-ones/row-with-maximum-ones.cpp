class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& arr) {
        int n = arr.size(); // row
        int m = arr[0].size(); // col
        int mxVal =  -1;
        int ans =  -1;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 1)count++;
            }
            if(mxVal < count){
                mxVal = count;
                    ans = i;}
        }
          return {ans, mxVal};
         
    }
};