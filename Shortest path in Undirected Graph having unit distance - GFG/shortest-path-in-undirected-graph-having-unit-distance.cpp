//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // min dist array
        vector<int> minDist(N, INT_MAX);
        minDist[src] = 0; // min distance from src to src is 0
        
        // Do a BFS
        queue<pair<int, int>> que;
        que.push({src, 0});
        
        while(!que.empty()){
            auto curr = que.front();
            que.pop();
            int node = curr.first, dist = curr.second;
            
            for(int next : adj[node]){
                if(dist+1 < minDist[next]) {
                    minDist[next] = dist+1;
                    que.push({next, dist+1});
                }
            }
        }
        for(int i =0; i<N; i++)
            if(minDist[i] == INT_MAX) minDist[i] = -1;
        
        return minDist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends