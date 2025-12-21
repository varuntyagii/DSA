class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();    // row
        int col = strs[0].size(); // col

        vector<bool> sorted(row, false);
        int deletion  = 0;
        for (int i = 0; i < col; i++) {
            bool count = false;
            for (int j = 0; j < row - 1; j++) {
                if (!sorted[j] && strs[j][i] > strs[j + 1][i]) {
                    deletion ++;
                    count = true;
                    break;
                }
            }
            if (count) {
                continue;
            }
            for (int r = 0; r < row - 1; r++) {
                sorted[r] = sorted[r] | (strs[r][i] < strs[r + 1][i]);
            }
        }
        return deletion;
    }
};