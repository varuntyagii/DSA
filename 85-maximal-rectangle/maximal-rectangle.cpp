class Solution {
public: 
       vector<int> getNSR(vector<int>& height){
        int n = height.size();
        stack<int>st;
        vector<int>NSR(n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && height[st.top()] >= height[i]){
                st.pop();
            }
            NSR[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return NSR;
    }
   vector<int> getNSL(vector<int>& height){
        int n = height.size();
        stack<int>st;
        vector<int>NSL(n);
        for(int i = 0; i < n; i++){
           while(!st.empty() && height[st.top()] >= height[i]){
                st.pop();
            }
            NSL[i] = st.empty() ? -1 : st.top();
            st.push(i);

        }
        return NSL;
    }
  int getMax(vector<int> &height){
        int n = height.size();
        vector<int>NSR = getNSR(height);
        vector<int>NSL = getNSL(height);
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int width = NSR[i] - NSL[i] - 1;
            maxArea = max(maxArea, width * height[i]);
        }
        return maxArea;
    }

   int maximalRectangle(vector<vector<char>>& mat) {

    // ✅ guard MUST be first
    if(mat.empty() || mat[0].empty()) return 0;

    int m = mat.size();
    int n = mat[0].size();

    vector<int> h(n);
    for(int i = 0; i < n; i++){
        h[i] = (mat[0][i] == '1') ? 1 : 0;
    }

    int maxArea = getMax(h);

    for(int r = 1; r < m; r++){
        for(int c = 0; c < n; c++){
            if(mat[r][c] == '1')
                h[c] += 1;
            else
                h[c] = 0;
        }
        maxArea = max(maxArea, getMax(h));
    }
    return maxArea;
}

};