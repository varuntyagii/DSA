class Solution {
public:
    typedef pair<int, int>p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        priority_queue<p, vector<p>, greater<p>>minHeap; // take using pair cause we traverse using freq og the map
        for(auto &num: nums){
            mp[num]++;
        }
        for(auto it: mp){
        int value = it.first;
        int freq = it.second;
        minHeap.push({freq, value});
            if(minHeap.size() > k)minHeap.pop();
        }
        vector<int>result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second); // value
            minHeap.pop();
        }
        return result;
    }
};