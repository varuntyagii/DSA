class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        int maxDig = 0;
        for(auto &it: dimensions){
            int l = it[0];
            int w = it[1];
            int dig = l*l + w*w;
            int area = l * w;
            if(dig > maxDig){
                maxDig = dig;
                maxArea = area;
            }
            else if(dig == maxDig){
                maxArea = max(area, maxArea);
            }

        }
        return maxArea;
    }
};