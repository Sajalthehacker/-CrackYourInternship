//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // Prims Algo
        vector<bool> vis(V, false);
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // ({edW, node}) coz only mst weighs asked here
        pq.push({0, 0});
        
        int mstWeight = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int edW = it.first, node = it.second;
            
            if(vis[node]) continue;
            vis[node] = true;
            mstWeight += edW;
            for(auto next : adj[node]){
                int nextNode = next[0], nextWeight = next[1];
                if(vis[nextNode]) continue;
                pq.push({nextWeight, nextNode});
            }
        }
        return mstWeight;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends