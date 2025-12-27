class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            usedRoom;
        priority_queue<int, vector<int>, greater<int>> aRoom;
        vector<int> resultCount(n, 0);

        sort(meetings.begin(), meetings.end());
        for (int room = 0; room < n; room++) {
            aRoom.push(room);
        }
        for (vector<int> meets : meetings) {
            int start = meets[0];
            int end = meets[1];
            int duration = end - start;
            while (!usedRoom.empty() && usedRoom.top().first <= start) {
                int room = usedRoom.top().second;
                usedRoom.pop();
                aRoom.push(room);
            }
            if (!aRoom.empty()) {
                int room = aRoom.top();
                aRoom.pop();
                usedRoom.push(
                    {end, room}); // end means that time free ho jayega
                resultCount[room]++;

            } else {
                int room = usedRoom.top().second;
                long long endTime = usedRoom.top().first + duration;
                usedRoom.pop();
                usedRoom.push({endTime, room});
                resultCount[room]++;
            }
        }
        int result = -1;
        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            if (resultCount[i] > maxVal) {
                maxVal = resultCount[i];
                result = i;
            }
        }
        return result;
    }
};