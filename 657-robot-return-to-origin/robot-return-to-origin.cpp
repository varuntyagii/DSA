class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for(auto ch: moves){
            if(ch == 'U') y++;
            if(ch == 'D') y--;
            if(ch == 'R') x++;
            if(ch == 'L') x--;

        }
        return x == 0 && y == 0;
    }
};