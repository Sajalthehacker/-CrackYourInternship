// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
 private:
    bool dfs(int source, vector<bool> &vis, vector<bool> &checker, vector<int> adj[]){
        vis[source] = true;
        checker[source] = true;
        
        for(int node : adj[source]){
            if(checker[node] == true) return true;
            if(vis[node] == false)
                if(dfs(node, vis, checker, adj)) return true;
        }
        checker[source] = false;
        return false;
    }
 public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> checker(V, false);
        
        for(int i=0; i<V; i++){
            if(vis[i] == false){
                if(dfs(i, vis, checker, adj)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends