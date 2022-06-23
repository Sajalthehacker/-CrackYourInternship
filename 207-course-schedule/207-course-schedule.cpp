class Solution {
private:
    bool dfs(int source, vector<bool> &vis, vector<bool>& check, vector<int> adj[]){
        vis[source] = true;
        check[source] = true;
        
        for(int it: adj[source]){
            if(check[it] == true) return true;
            if(vis[it] == false){
                if(dfs(it, vis, check, adj)) return true;
            }
        }
        check[source] = false;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        
        // In this question, we just have to check if there is cycle present
        // If there is a cycle, it creates a deadlock, adn none of course cmpletes
        
        vector<int> adj[n];
        vector<bool> vis(n, false);
        vector<bool> check(n, false);

        for(auto it : prereq){
            adj[it[0]].push_back(it[1]);
        }
        
        for(int i=0;i<n;i++){
            if(dfs(i, vis, check, adj))
                return false;
        }
        return true;
    }
};