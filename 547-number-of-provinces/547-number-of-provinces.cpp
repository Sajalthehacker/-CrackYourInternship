class Solution {
private:
    void dfs(int node, vector<bool> &vis, vector<int> adj[]){
        vis[node] = true;
        for(int it : adj[node]){
            if(!vis[it]) dfs(it, vis, adj);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i = 0 ; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    if(i == j) continue;
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n, false);
        
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};