// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void solve(int node,int parent,int &timer,vector<int> &low,vector<int> &tin,vector<int> &vis,vector<int> adj[],vector<int> &ans){
        vis[node] = 1;
        low[node] = tin[node] = timer++;
        
        int child = 0;
        for(auto &it : adj[node]){
            if(it == parent)
                continue;
            if(!vis[it]){
                solve(it,node,timer,low,tin,vis,adj,ans);
                low[node] = min(low[node],low[it]);
                if(tin[node] <= low[it] and parent != -1){
                    ans.push_back(node);
                }
                child++;
            }else{
                low[node] = min(low[node],tin[it]);       
            }
        }
        if(child > 1 and parent == -1){
            ans.push_back(node);
        }
    }
  
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        vector<int> ans;
        vector<int> low(v);
        vector<int> tin(v);
        vector<int> vis(v);
        
        int timer = 0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                solve(i,-1,timer,low,tin,vis,adj,ans);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        if(ans.size() == 0){
            return {-1};
        }
        return ans;
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
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends