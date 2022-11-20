//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void ts(int V, vector<int> adj[], string &ans) 
	{
	    // code here
	    vector<int> indegree(V, 0);
	    for(int i=0; i<V; i++)
	        for(auto itt : adj[i]) indegree[itt]++;
        
        queue<int> que;
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0) que.push(i);
        }
        
	    while(!que.empty()){
	        int node = que.front();
	        que.pop();
	        
	        ans += char(97 + node);
	        for(int it : adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) que.push(it);
	        }
	    }
	}
    

    string findOrder(string dict[], int n, int k) {
        //code here
        vector<int> adj[k];
        string ans = "";
        for(int i=0 ;i<n-1; i++){
            for(int j=0; j<min(dict[i].size(), dict[i+1].size()); j++){
                if(dict[i][j] != dict[i+1][j]){
                    adj[(dict[i][j] - 'a')].push_back(dict[i+1][j] - 'a');
                    break;
                }
            }
        }
        ts(k, adj, ans);
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends