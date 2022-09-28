class Solution {
private:
    bool check(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<int>> &mat){
        return (i>=0 && j>=0 && i<n && j<m && !vis[i][j] && mat[i][j] == 1);
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> que;
        
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    que.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }
        
        while(!que.empty()){
            auto node = que.front();
            que.pop();
            
            int x = node.first.first, y = node.first.second;
            int currLvl = node.second;
            
            ans[x][y] = currLvl;
            vis[x][y] = true;
            
            for(auto it : dir){
                if(check(x+it[0], y+it[1], n, m, vis, mat)){
                    vis[x+it[0]][y+it[1]] = true;
                    que.push({{x+it[0], y+it[1]}, currLvl+1});
                }
            }
        }
        
        return ans;
    }
};