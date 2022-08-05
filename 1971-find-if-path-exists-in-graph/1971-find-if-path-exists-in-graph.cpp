class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Making Adjacency list
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n, false);
        vis[source] = true;
        
        // Running a BFS to search the node
        // Choosed BFS coz, there isn't extra stack space involved in BFS
        queue<int> que;
        que.push(source);
        while(!que.empty()){
            int node = que.front();
            vis[node] = true;
            que.pop();
            // Checking if pre node is the destination node
            if(node == destination) return true;
            for(int it : adj[node]) 
                if(vis[it] == false) que.push(it);
        }
        return false;
    }
};