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

        // j = 1 to n
        for (int j = 1; j <= n; j++) {
            // j-1 hour ka effect adjust karo
            if (customers[j - 1] == 'Y') {
                penalty--; // pehle closed tha, ab open → penalty kam
            } else {
                penalty++; // pehle open tha aur 'N' → penalty badh
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j;
            }
        }

        return bestHour;
    }
};
