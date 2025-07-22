class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        //
        bool container = false;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                container = true;
            }
            if (arr[i] <= 0 || arr[i] > n) {
                arr[i] = 1;
            }
        }
        if (container == false) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            int num = abs(arr[i]);
            int idx = num - 1;
            if (arr[idx] < 0) {
                continue;
            }
            arr[idx] *= -1;
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                continue;
            }
            return i + 1;
        }
        return n + 1;
    }
};