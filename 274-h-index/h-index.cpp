class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(); 
        vector<int>temp(n + 1, 0);
        for(int c: citations){
            if(c > n){
                // 6 < 7 = temp[6] = 0 = 0++ = 1;
                temp[n]++; //ex = n = 6 c = 7,8 vector mei uss jagah par tum uska count bdha do;
            }
            else{
                //6 < 5 = 0, 0++ = 1 position at the index of 5 increased by 1;
                temp[c]++;
            }
        }
        int count = 0; 
        for(int i = n; i >= 0; i--){
                        count += temp[i];

            if(count >= i){
                return i;
                break;
            }
        }
        return 0;
    }
};
//Jitni baar alag-alag researchers tere paper ko reference denge, utni tere citations increase hote hain.
// Aur ye hi H-index calculate karne me kaam aata hai.