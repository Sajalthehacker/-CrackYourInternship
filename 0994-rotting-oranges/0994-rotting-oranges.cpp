class Solution {
private:
    bool check(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<int>> &grid){
        return (i>=0 && j>=0 && i<n && j<m && !vis[i][j] && grid[i][j] == 1);
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS Solution
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue <pair<pair<int, int>, int>> que;
        int maxTime = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = true;
                    que.push({{i, j}, 0});
                }
            }
        }
        cout << que.size() << endl;
        while (!que.empty()){
            auto node = que.front();
            que.pop();
            
            int currTime = node.second;
            maxTime = max(currTime, maxTime);
            int x = node.first.first, y = node.first.second;
            vis[x][y] = true;
            grid[x][y] = 2;
            
            if(check(x+1, y, n, m, vis, grid)){
                vis[x+1][y] = true;
                que.push({{x+1, y}, currTime+1});
            }
            if(check(x-1, y, n, m, vis, grid)){
                vis[x-1][y] = true;
                que.push({{x-1, y}, currTime+1});
            }
            if(check(x, y+1, n, m, vis, grid)){
                vis[x][y+1] = true;
                que.push({{x, y+1}, currTime+1});
            }
            if(check(x, y-1, n, m, vis, grid)){
                vis[x][y-1] = true;
                que.push({{x, y-1}, currTime+1});
            }
        }
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 1 && vis[i][j] == false) return -1;

        return maxTime;
    }
};