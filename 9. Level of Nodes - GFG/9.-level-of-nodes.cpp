// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution

{
    public:
    int nodeLevel(int V, vector<int> adj[], int X) 
    { 
        int level[V]={};
        vector<bool> visited(V,0);
        
        level[0]=0;
        visited[0]=true ;
        
        queue<int> q;
        
        q.push(0);
        
        
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
           for(auto s:adj[a])
            {
                if(!visited[s]){
                level[s]=level[a]+1;
                if(s==X)
                {
                   return level[s];
                }
                visited[s]=1;
                q.push(s);}
            }
        }
        return -1;
    }

};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends