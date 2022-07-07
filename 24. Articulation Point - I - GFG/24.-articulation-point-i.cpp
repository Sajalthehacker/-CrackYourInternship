// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<int> adj[],int src,int p,vector<int>&vis,vector<int>&dp,int depth,vector<int> &ans)
{
     vis[src]=1;
     dp[src]=depth;
     int child=0;
     int maxi=-1;
     for(auto t:adj[src])
        {
          if(vis[t]==0)
          {
            child++;
            dfs(adj,t,src,vis,dp,depth+1,ans);
            maxi=max(maxi,dp[t]);
          }
        }
     
      if(p!=-1)
       child++;
     if(child>1&&depth<=maxi)
           ans.push_back(src);

     for(auto t:adj[src])
         if(t!=p)
             dp[src]=min(dp[src],dp[t]);
}

vector<int> articulationPoints(int n, vector<int>adj[])
{
    vector<int> dp(n,0);
    vector<int> vis(n,0);
    int depth=0;
    vector<int> ans;
    dfs(adj,0,-1,vis,dp,depth,ans);
    sort(ans.begin(),ans.end());
    if(ans.size()==0)
     ans.push_back(-1);
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