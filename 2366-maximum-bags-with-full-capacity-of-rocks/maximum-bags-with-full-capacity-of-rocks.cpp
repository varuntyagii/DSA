class Solution {
public:
    int maximumBags(vector<int>& arr, vector<int>& rocks, int a) {
        int m = arr.size();
        int n = rocks.size();
        // for(int i = 0; i < m; i++){
        //     if(arr[i] > rocks[i]){
               
        //        if(a > 0){
        //          rocks[i]++;
        //        }
        //         a--;
        //     }
        //     if(arr[i] == rocks[i]){
        //         count++;
        //     }

        // }
       vector<int>req(n);
      for(int i = 0; i < m; i++){
        req[i] = arr[i] - rocks[i];
       }
       sort(req.begin(), req.end());
       int count = 0;
       for(int i = 0; i < req.size(); i++){
        if(req[i] == 0){
            count++;
        }
        else{
            if(a >= req[i]){
                a = a - req[i]; 
                count++;
            }
            else{
                break;
            }
        }
       
       }
       return count;
    }
};