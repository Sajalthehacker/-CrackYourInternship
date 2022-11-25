//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
 private:
    void dfs(int node, stack<int>&stt, vector<bool> &vis, vector<pair<int, int>> adj[]){
        vis[node] = true;
        for(auto it : adj[node]){
            if(vis[it.first] == false) dfs(it.first, stt, vis, adj);
        }
        stt.push(node);
    }   
 public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        // Make Adj list
        vector<pair<int, int>> adj[N];
        vector<bool> vis(N, false);
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        // Find the Topo Sort of Graph
        stack<int> stt;
        for(int i = 0; i<N; i++)
            if(vis[i] == false) dfs(i, stt, vis, adj);
        
        
        vector<int> minDist(N, 1e9);
        minDist[0] = 0;
        while(!stt.empty()){
            int curr = stt.top();
            stt.pop();
            for(auto it : adj[curr]){
                minDist[it.first] = min(minDist[it.first], minDist[curr] + it.second);
            }
        }
        for(int i=0; i<N; i++)
            if(minDist[i] == 1e9) minDist[i] = -1;
        
        return minDist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends