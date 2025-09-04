class Solution {
public:
    int findClosest(int x, int y, int z) {
      
        int minVal = INT_MAX;
        int xy = abs(x - z);
        int yz = abs(y - z);
        if(xy < yz){
            return 1;
        }
        
       else if(xy > yz){
            return 2;
        }
        return 0;
        
    }
};