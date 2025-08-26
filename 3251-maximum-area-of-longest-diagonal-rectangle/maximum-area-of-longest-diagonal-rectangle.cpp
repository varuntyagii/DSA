class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int mx = 0;      // maximum diagonal^2
        int area = 0;    // area corresponding to max diagonal
        for(auto& i : dimensions){
            int a = i[0];
            int b = i[1];
            int dig = (a*a + b*b);   // diagonal^2
            int aarea = a * b;       // area

            if(dig > mx){   // bigger diagonal found
                mx = dig;
                area = aarea;
            }
            else if(dig == mx){  // same diagonal length
                area = max(area, aarea); // choose bigger area
            }
        }
        return area;
    }
};
