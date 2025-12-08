class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){
               int c = a * a + b * b;
               int root = sqrt(c);
               if(root <= n && root * root == c){
                count++;
               }
            }
        }
        return count;
    }
};