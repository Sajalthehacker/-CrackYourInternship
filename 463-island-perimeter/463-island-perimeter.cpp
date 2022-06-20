class Solution {
private:
    int n, m;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    bool isValid(int i, int j, vector<vector<int>>& grid){
        return i>=0 && j>=0 && i<n && j<m && grid[i][j]==1;
    }
    
    int checkBoundaries(int i, int j, vector<vector<int>>& grid){
        int cnt = 0;
        for(auto it : directions){
            if(isValid(i+it[0], j+it[1], grid)) cnt++;
        }
        return cnt;
    }
    
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        int perimeter = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    int oneCount = checkBoundaries(i, j, grid);
                    perimeter += (4-oneCount);
                }
            }
        }
        return perimeter;

    }
};