class Solution {
private:
    vector<vector<int>> allPaths;
    int n;
    
    // void dfs(int vertex, vector<int> &prePath, vector<vector<int>>& adj, vector<bool> vis){
    //     vis[vertex] = true;
    //     prePath.push_back(vertex);
    //     if(vertex == n-1){
    //         allPaths.push_back(prePath);
    //     }
    //     for(int child : adj[vertex]){
    //         if(vis[child]) continue;
    //         dfs(child, prePath, adj, vis);
    //     }
    //     prePath.pop_back();
    //     vis[vertex] = false;
    // }
    
    
    void dfs(int vertex, vector<int> &prePath, vector<vector<int>>& adj, vector<bool> &vis){
        vis[vertex] = true;
        prePath.push_back(vertex);
        if(vertex == n-1){
            allPaths.push_back(prePath);
        }
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