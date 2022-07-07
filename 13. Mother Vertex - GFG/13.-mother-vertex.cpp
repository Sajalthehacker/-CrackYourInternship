// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
    int dfs(int node, vector<int> adj[], vector<bool>&vis, vector<bool>&dfsvis) {
        vis[node]=1; dfsvis[node]=1;
        int count=1;
        for(int it:adj[node]) {
            if(!vis[it]) {
                count+=dfs(it,adj,vis,dfsvis);
            }
        }
        dfsvis[node]=0;
        return count;
    }
    public:
	int findMotherVertex(int v, vector<int>adj[]) {
	    vector<bool> vis(v,0), dfsvis(v,0);
	    for(int i=0; i<v; i++) {
	        int count=dfs(i,adj,vis,dfsvis);
	        if(count==v) return i;
	    }
	    return -1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends