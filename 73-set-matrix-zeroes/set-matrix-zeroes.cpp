class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();   // row
        int n = mat[0].size(); // col
                vector<int>
                    row(m, false);
        vector<int> col(n, false);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == true || col[j] == true) {
                    mat[i][j] = 0;
                }
            }
        }
    }
};