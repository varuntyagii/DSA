class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;

         vector<vector<int>> result;
        int n = intervals.size();
        while(i < n){
            //
            if(intervals[i][1] < newInterval[0]){
             result.push_back(intervals[i]);
                // Tum agar intervals[i][0] likhte, tab sirf 1 aata.
                // Agar intervals[i][1] likhte, tab sirf 2 aata.
                // Lekin intervals[i] likhne se poora pair copy hota hai.
            }
            else if(newInterval[1] < intervals[i][0] ){
               break; // why this cause after this we are just inserting the newInterval when conflict occurs here 
            }
            else{
                // merge yha par conflit aaya hai to min max niklna hai fir merge
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);

            }
            i++;
        }
         result.push_back(newInterval);
       for(; i < n; i++){
            result.push_back(intervals[i]);
         
       }
        return result;
    }
};