class Solution {
public:
    bool isPowerOfTwo(int n) {
    vector<int>powers = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512,
                    1024, 2048, 4096, 8192, 16384, 32768,
                    65536, 131072, 262144, 524288, 1048576,
                    2097152, 4194304, 8388608, 16777216,
                    33554432, 67108864, 134217728, 268435456,
                    536870912, 1073741824}; // when u are using the int then it will reach upto the 2^30 = 1073741824
                    //Your vector stops at 2^30 because 2^31 can’t be stored in a positive signed int.
    for (int p : powers) {
        if (p == n) return true;
    }
    return false;
}

};