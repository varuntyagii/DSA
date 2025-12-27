class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
    int low = mat[0][0], high = mat[n-1][n-1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        for (int i = 0; i < n; i++) {
            count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        } //running with (n)

        if (count < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
    }
};
//Total TC=O(n⋅logn⋅log(maxVal−minVal))