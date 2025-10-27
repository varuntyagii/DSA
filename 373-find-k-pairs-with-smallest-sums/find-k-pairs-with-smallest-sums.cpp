class Solution {
public:
   typedef pair<int, pair<int, int>> p;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p, vector<p>, greater<p>>pq;
        vector<vector<int>>result;
        set<pair<int, int>>visit;
        // sbse smallest element to starting mei milenge
        int m = nums1.size();
        int n = nums2.size();
        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0, 0}});
        visit.insert({0, 0});
        while(k-- && !pq.empty()){
            auto temp = pq.top();
            pq.pop();
            //explore
            int i = temp.second.first;
            int j = temp.second.second;
            result.push_back({nums1[i], nums2[j]});
            // (i, j + 1);
            if(j + 1 < n && visit.find({i, j + 1}) == visit.end()){
                pq.push({{nums1[i] + nums2[j + 1]}, {i, j + 1}});
                visit.insert({i, j + 1});
            }
            // (i + 1, j);
            if(i + 1 < m && visit.find({i + 1, j}) == visit.end()){
                pq.push({{nums1[i + 1] + nums2[j]}, {i + 1, j}});
                visit.insert({i + 1, j});

            }

        }
        return result;
    }
};