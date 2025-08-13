class Solution {
public:
    bool check(int n ){
        if( n == 1)return true;
        if(n <= 0 || n % 3 != 0)return false;

       return check(n/3);
    }
    bool isPowerOfThree(int n) {
       return check(n);

    }
};

//third approach tc = (log3*n) sc = O(1)/log3(n)