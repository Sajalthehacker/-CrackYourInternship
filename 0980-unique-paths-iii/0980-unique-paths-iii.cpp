class Solution {
public:
    int cnt = 0;
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i<0 || j < 0 || i>=n || j >= m || grid[i][j] == -1 || grid[i][j] == 3){
            return false;
        }
        return true;
    }
    
    int fn(int i, int j, int n, int m, int &currCnt, vector<vector<int>>& grid){
        if(grid[i][j] == 2) {
            // cout << cnt << " " << currCnt << endl;
            if(currCnt+1 == cnt) return 1;
            else return 0;
        }
        int ans = 0;
        currCnt++;
        grid[i][j] = 3;
        if(isValid(i+1, j, n, m, grid)) ans += fn(i+1, j, n, m, currCnt, grid);
        if(isValid(i, j+1, n, m, grid)) ans += fn(i, j+1, n, m, currCnt, grid);
        if(isValid(i-1, j, n, m, grid)) ans += fn(i-1, j, n, m, currCnt, grid);
        if(isValid(i, j-1, n, m, grid)) ans += fn(i, j-1, n, m, currCnt, grid);
        grid[i][j] = 0;
        currCnt--;
        return ans;
    }
        
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int currCnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0 || grid[i][j] == 1 || grid[i][j] == 2) cnt++;        
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    return fn(i, j, n, m, currCnt, grid);
                }
            }
        }
        return 0;
    }
};