// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  private:
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid){
        int n = grid.size(), m = grid[0].size();
        //base case
        if (i<0 || j<0 || i>=n || j>=m ||grid[i][j]=='0' || vis[i][j]==true) return;
        
        vis[i][j] = true;
        dfs(i-1, j, vis, grid);
        dfs(i, j-1, vis, grid);
        dfs(i, j+1, vis, grid);
        dfs(i+1, j, vis, grid);
        
        dfs(i-1, j-1, vis, grid);
        dfs(i-1, j+1, vis, grid);
        dfs(i+1, j+1, vis, grid);
        dfs(i+1, j-1, vis, grid);
    }
  public:
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends