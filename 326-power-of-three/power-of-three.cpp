class Solution {
public:
    bool check(int n ){
        if(n <= 0)return false;
        if( n == 1)return true;
        if(n % 3 != 0)return false;

       return check(n/3);
    }
    bool isPowerOfThree(int n) {
       return check(n);

    }
};