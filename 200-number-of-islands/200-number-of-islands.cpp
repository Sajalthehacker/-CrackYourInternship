class Solution {
private:
    int n, m, cnt = 0;
    int directions[4][2] ={{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; 
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        
        if(i<0 || j<0 || i>=n || j>=m) return; // Index out of bounds condition
        if (grid[i][j] != '1' || vis[i][j]) return; // No Bridge Condition

        vis[i][j] = true;
        // cout << cnt << " ";
        // Further dfs calls : up, down, right, left
        // dfs(i+1, j, vis, grid); // dfs(i-1, j, vis, grid); 
        // dfs(i, j+1, vis, grid); // dfs(i, j-1, vis, grid);
        // These four manual calls can be written cleanly as direction array
        for(auto it : directions){
            dfs(i+it[0], j+it[1], vis, grid);
        }

    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == false && grid[i][j] == '1'){
                    // increse the cnt and make a dfs call
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};