class Solution {
private:
    vector<vector<int>> allPaths;
    int n;
    
    void dfs(int vertex, vector<int> &prePath, vector<vector<int>>& adj, vector<bool> vis){
        if(vertex == n-1){
            prePath.push_back(vertex);
            allPaths.push_back(prePath);
            prePath.pop_back();
            return;
        }
        vis[vertex] = true;
        prePath.push_back(vertex);
        for(int child : adj[vertex]){
            if(vis[child]) continue;
            dfs(child, prePath, adj, vis);
        }
        prePath.pop_back();
        vis[vertex] = false;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        n = adj.size();
        vector<int> prePath;
        vector<bool> vis(n, false);
        dfs(0, prePath, adj, vis);
        return allPaths;
    }
};