class Solution {
private:
    int n;
    int proCount = 0;
    void dfs(int source, vector<bool> &vis, vector<vector<int>> &isConnected){
        vis[source] = true;
        for(int i=0; i<n; i++){
            if(!vis[i] && isConnected[source][i] == 1) {
                vis[i] = true;
                dfs(i, vis, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> vis(n, false);
        
        for(int i=0; i<n; i++){
            if(vis[i] == false){
                dfs(i, vis, isConnected);
                proCount++;
            }
        }
        return proCount;
    }
};