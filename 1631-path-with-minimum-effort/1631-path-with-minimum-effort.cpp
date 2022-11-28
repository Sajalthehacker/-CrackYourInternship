class Solution {
private:
    bool isValid (int newRow, int newCol, int n, int m){
        return (newRow < n && newCol < m && newRow >= 0 && newCol >= 0);
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Question based on Dijkstra's Algo
        // queue : {dist, {row, col}};
        priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;
        
        int n = heights.size(), m = heights[0].size();
        // stores min difference to that (r, c)
        vector<vector<int>> effort(n, vector<int> (m, 1e9));
        effort[0][0] = 0;
        pq.push({0, {0, 0}});
        
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // for 4 directions
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            // If we end up at nottom right at any time, its is the least effort we could get
            int currEffort = curr.first, row = curr.second.first, col = curr.second.second;
            if(row == n-1 && col == m-1) return currEffort;
            for(auto d : dir){
                int newRow = row + d[0], newCol = col + d[1];
                if(isValid(newRow, newCol, n, m)){
                    int newEffort = max(currEffort, abs(heights[newRow][newCol] - heights[row][col]));
                    if(newEffort < effort[newRow][newCol]){
                        effort[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }
        
        return 0;
        
    }
};