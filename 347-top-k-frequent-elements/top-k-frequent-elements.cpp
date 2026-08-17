//vo k element return kro joki sbse jada aa rhe hai mtlb frequency ke basis par element return kro 
class Solution {
public:
    typedef pair<int,int>data;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //minheap
       unordered_map<int, int>mp;
       for(auto i: nums){
        mp[i]++;
       }
       priority_queue<data, vector<data>, greater<data>>pq;

       for(auto p: mp){
        int value = p.first; // [1,1,1,2,2] 
        int freq = p.second; // {1->3, 2->2}
        pq.push({freq, value});
        //if()
        if(pq.size() > k)pq.pop();
       }
       vector<int>res;
       while(!pq.empty()){
        int num = pq.top().second; // value
        res.push_back(num);
        pq.pop();
       }
       return res;
    }
};