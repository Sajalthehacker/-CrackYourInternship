class Solution {
private:
    int n, m, cnt = 0;
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        // Base Case
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] != '1' || vis[i][j]) return;
        
        vis[i][j] = true;
        // cout << cnt << " ";
        // Further dfs calls
        dfs(i+1, j, vis, grid);        
        dfs(i-1, j, vis, grid);
        dfs(i, j+1, vis, grid);
        dfs(i, j-1, vis, grid);

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