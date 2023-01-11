class Solution {
public:
    int dfs(int node, int parent, vector<int> adj[], vector<bool>& hasApple){
        int time = 0;
        for(int it : adj[node]){
            if(it == parent) continue;
            time += dfs(it, node, adj, hasApple);
        }
        
        if(hasApple[node] || time > 0){
            return (2 + time); 
        }
        return time;
    }
    
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        vector<bool> vis(n, false);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = dfs(0, -1, adj, hasApple);
        if(ans > 0) return ans - 2;
        return ans;
    }
};