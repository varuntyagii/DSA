class Solution {
public:
    bool isPowerOfTwo(int n) {
    // return pow(2,n);
for(int i=0;i<31;i++){
   int ans = pow(2,i);
    if(ans==n)return true;
}
return false;
    }  
};