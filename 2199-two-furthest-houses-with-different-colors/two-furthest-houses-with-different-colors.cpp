class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0, j = n - 1;

        // case 1: fix i = 0, move j
        while(colors[i] == colors[j]) {
            j--;
        }
        int ans1 = j - i;

        // case 2: fix j = n-1, move i
        i = 0, j = n - 1;
        while(colors[i] == colors[j]) {
            i++;
        }
        int ans2 = j - i;

        return max(ans1, ans2);
    }
};