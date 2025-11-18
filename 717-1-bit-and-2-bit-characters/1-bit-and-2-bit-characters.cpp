class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = n - 2;
        int count = 0; // agr last mei 0 bach rha toh thik lekin agr 11 or 10 bn ra hai toh galat hai 
        while(i >= 0 && bits[i] == 1){
            count++;
            i--;
        }
        return count % 2 == 0 ? true: false;
    }
};