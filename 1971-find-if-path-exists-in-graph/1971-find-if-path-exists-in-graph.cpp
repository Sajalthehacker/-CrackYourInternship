class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        vector<int> adj[n];
        vector<bool> vis(n, false);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> que;
        que.push(source);
        while(!que.empty()){
            int node = que.front();
            que.pop();
            vis[node] = true;
            if(node == dest){
                return true;
            }
            for(int it : adj[node]){
                if(!vis[it]) que.push(it);
            }
        }
        return false;
        
    }
};