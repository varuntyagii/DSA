class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<bool>sus(n, false);
        vector<int>inDegree(n, 0);
        for(auto &edge: invocations){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        //bfs
        queue<int>q;
        q.push(k);
        sus[k] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int& ngbr: adj[curr]){
                inDegree[ngbr]--;
                if(!sus[ngbr]){
                    q.push(ngbr);
                    sus[ngbr] = true;
                }

            }


        }
          vector<int> res;

        for (int i = 0; i < n; i++) {

            if (sus[i] && inDegree[i] > 0) {
                vector<int> vec;
                for (int j = 0; j < n; j++) {
                    vec.push_back(j);
                }
                return vec;
            }

            if (!sus[i]) {
                res.push_back(i);
            }
        }
        return res;
        
    }
};