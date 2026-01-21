class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
               stack<int> st;  // store indices

        vector<int>ans(n,0);

        for(int i = 0; i < n; i++){
            while(!st.empty() && temp[i] > temp[st.top()]){
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;  // days until warmer temperature
            }
            st.push(i);

        }
        return ans;
    }
};