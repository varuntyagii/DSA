class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int mx = 0;
        int area = 0;
        for(auto& i : dimensions){
            int a = i[0];
            int b = i[1];
            int dig = (a*a + b*b);
            int aarea = a * b;
            if(dig > mx){
                mx = dig;
                area = aarea;
            }
            else if(dig == mx){
               area = max(area, aarea);
            }

        }
        return area;
    }
};