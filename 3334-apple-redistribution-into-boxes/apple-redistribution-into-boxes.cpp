class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        sort(capacity.begin(), capacity.end());
        int count = 0;
        for(auto num: apple){
            count += num;
        }
        int used = 1;
        int c = 0;
        for(int i = m - 1; i >= 0; i--){
            c += capacity[i];
            if(c >= count){
                return used;
            }
            used++;
        }
        return used;
    }
};