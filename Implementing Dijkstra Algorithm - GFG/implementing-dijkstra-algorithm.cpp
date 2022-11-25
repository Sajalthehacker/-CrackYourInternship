//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // create adj list
        vector<int> minDist(V, 1e9);

        // priority_queue<pair<int, int> ,vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<pair<int, int>> stt;
        
        // Dijkstra's Algo
        stt.insert({0, S}); // forma to push in pq : {dist, node}
        minDist[S] = 0;
        int mini = S;
        
        while(!stt.empty()){
 
            auto curr = *stt.begin();
            stt.erase(curr);
            for(auto it : adj[curr.second]){
                int dist = it[1], node = it[0];
                if(dist + minDist[curr.second] < minDist[node]){
                    minDist[node] = dist + minDist[curr.second];
                    stt.insert({dist + minDist[curr.second], node});
                }
            }
        }
        for(int i=0; i<V; i++)
            if(minDist[i] == 1e9) minDist[i] = -1;
        
        return minDist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends