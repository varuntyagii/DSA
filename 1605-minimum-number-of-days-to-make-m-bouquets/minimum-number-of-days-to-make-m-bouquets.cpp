class Solution {
public:
    int check(vector<int>&bloomDay, int mid, int k){
        int total = 0;
        int consicutive = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                consicutive++;
            }
            else{
                consicutive = 0;
               
            }
            if(consicutive == k){
                total++;
                 consicutive = 0;
            }
        }
        return total;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int start = 0;
        int end = INT_MIN;
            //   if (1LL * m * k > n) return -1; // not enough flowers
        for(int num: bloomDay){
            end = max(end, num);
        }
        int result = -1;
        while(start <= end){
            int mid = start + (end - start)/2;

            if(check(bloomDay, mid, k) >= m){
                result = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return result;
    }
};