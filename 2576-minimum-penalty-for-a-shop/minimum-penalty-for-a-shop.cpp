class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int penalty = 0;

        // Initial penalty: shop closes at 0
        // saare 'Y' penalty denge
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestHour = 0;

        for(int i = 0; i < n; i++){
            if(customers[i] == 'Y'){
                penalty--;
            }
            else{
                penalty++;
            }
            if(minPenalty > penalty){
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }
        return bestHour;
        
    }
};
