class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int dash = 0;
        int left = 0;
        int right = 0;
        for(auto i: moves){
            if(i == 'L')left++;
            else if(i == 'R')right++;
            else dash++;
        }
        return abs(left - right) + dash;
    }
};