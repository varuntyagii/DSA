class Solution {
public:
    void build(int i, int l, int r, vector<int>& baskets,
               vector<int>& segmentTree) {
        if (l == r) {
            segmentTree[i] = baskets[l];
            return;
        }
        // find mid
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid, baskets, segmentTree);     // Left child
        build(2 * i + 2, mid + 1, r, baskets, segmentTree); // Right child
        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }

    bool querysegmentTree(int i, int l, int r, vector<int>& segmentTree,
                         int t) {
        // segmentTree jo hai vo basket ki capacity store krra hai so if
        // segmentTree ki value choti  hai fruits se toh koi mtlb nhi bnta store
        // krne ka kyuki segmentTree ke pass root ke maxVal hoti hai
        if(segmentTree[i] < t){
            return false;
        }
        if(l == r){
            segmentTree[i] = -1;
            return true;
        }
        int mid = l + (r - l)/2;
        bool placed = false;
        if(segmentTree[2 * i + 1] >= t){ // left wale ki value choti fruits se toh left side mei chalo tree ke 
        placed = querysegmentTree(2*i+1, l, mid, segmentTree, t) ? true : false;

        }
        else{
                placed = querysegmentTree(2*i+2, mid+1, r, segmentTree, t) ? true : false;
        }
        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        return placed;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segmentTree(4 * n, -1);
        build(0, 0, n - 1, baskets, segmentTree);
        // traverse each and every fruits;
        int unplaced = 0;
        for (int t : fruits) {

            if (querysegmentTree(0, 0, n - 1, segmentTree, t) == false) {
                unplaced++;
            }
        }
        return unplaced;
    }
};