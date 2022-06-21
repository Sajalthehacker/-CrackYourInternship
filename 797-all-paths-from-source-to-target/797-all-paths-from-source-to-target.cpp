class Solution {
private:
    int n;
    vector<vector<int>> allPaths;
    vector<bool> vis;
    
    void dfs(int node, vector<int> &path, vector<vector<int>>& graph){
        
        vis[node] = true;
        path.push_back(node);
        
        if(node == n-1){
            allPaths.push_back(path);
            // return;
        }
        
        for(int it : graph[node]){
            if(vis[it]) continue;
            dfs(it, path, graph);
            vis[it] = false;
        }
        
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vis.resize(n, false);
        vector<int> path;
        
        dfs(0, path, graph);
        return allPaths;
        
    }
};