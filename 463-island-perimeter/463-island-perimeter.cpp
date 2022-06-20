class Solution {
private:
    int n, m, waterCnt=0;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
     void dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0){
            waterCnt++;
            return;
        } 
        if(grid[i][j] == -1) return;

        grid[i][j] = -1; // If we arent allowed to modify grid, visited array can be used.
        for(auto it : directions){
            dfs(i+it[0], j+it[1], grid);
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid);
                    break;
                }
            }
        }
        return waterCnt;

    }
};