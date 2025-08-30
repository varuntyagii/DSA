class Solution {
public:
    bool travels(vector<vector<char>>&grid, int sr, int er, int sc, int ec){
            unordered_set<char>st;
        for(int i = sr; i <= er; i++){
            for(int j = sc; j <= ec; j++){
                if (grid[i][j] == '.') continue; 
                if(st.find(grid[i][j])!= st.end()){
                    return false;
                }
                st.insert(grid[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //visit for row
        for(int i = 0; i < 9; i++){
            unordered_set<char>st;
            for(int j = 0; j < 9; j++){
                if((grid[i][j]) == '.'){
                    continue;
                }
                if(st.find(grid[i][j]) != st.end()){
                    return false;
                }
                st.insert(grid[i][j]);
            }
        }
        //visit for col
        for(int j = 0; j < 9; j++){
            unordered_set<char>st;
            for(int i = 0; i < 9; i++){
                if((grid[i][j]) == '.'){
                    continue;
                }
                if(st.find(grid[i][j]) != st.end()){
                    return false;
                }
                st.insert(grid[i][j]);
            }
        }
        // validate for 3*3 each boxs
        
        for(int sr = 0; sr < 9; sr+=3){
            int er = sr + 2;
            for(int sc = 0; sc < 9; sc+=3){
                int ec = sc + 2;
                    if(!travels(grid, sr, er, sc, ec)){
                        return false;
                    }
            }
        }
        return true;
    }
};