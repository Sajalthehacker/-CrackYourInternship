class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Make Adjacency List
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        // Run a BFS to find the path from source to destination
        vector<bool> vis(n, false);
        queue<int> que;
        que.push(source);
        
        while(!que.empty()){
            int node = que.front();
            vis[node] = true;
            que.pop();
            
            if(node == destination) return true;
            
            for(int it : adj[node]){
                if(vis[it]) continue;
                que.push(it);
            }
        }
        return false;
    }
};