class Solution {
private:
    int maxi = 0;
    int dfs(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<int>>& grid){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || vis[i][j]) return 0;
        
        vis[i][j] = true;
        
        return 1 + dfs(i+1, j, n, m, vis, grid) 
                 + dfs(i, j+1, n, m, vis, grid)
                 + dfs(i-1, j, n, m, vis, grid)
                 + dfs(i, j-1, n, m, vis, grid);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == false)
                    maxi = max(maxi, dfs(i, j, n, m, vis, grid));
            }
        }
        return maxi;
    }
};