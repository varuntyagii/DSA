class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m < 3 || n < 3) return 0; // Too small to trap any water

        // Min-heap to process cells by height
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap; // heigh, {i , j}
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add all boundary cells to the heap
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        int waterTrapped = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 4 directions: right, down, left, up

        // Process cells in the priority queue
        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top();
            minHeap.pop();

            int x = cell.first, y = cell.second;

            // Explore neighbors
            for (auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                // Skip out-of-bounds or already visited cells
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;

                // Calculate trapped water for the neighbor
                waterTrapped += max(0, height - heightMap[nx][ny]);

                // Update the neighbor's height and mark it as visited
                minHeap.push({max(height, heightMap[nx][ny]), {nx, ny}});
                visited[nx][ny] = true;
            }
        }

        return waterTrapped;
    }
};