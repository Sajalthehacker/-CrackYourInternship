// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
private:
    vector<string> ans;
    void dfs(int i, int j, int n, string str, vector<vector<bool>> &vis, vector<vector<int>> &maze){
        if(i<0 || j<0 || i>=n || j>=n) return;
        if(vis[i][j] || maze[i][j] == 0) return;
        
        if(i==n-1 && j==n-1) ans.push_back(str);
        vis[i][j] = true;
        dfs(i+1, j, n, str+'D', vis, maze);
        dfs(i, j-1, n, str+'L', vis, maze);
        dfs(i, j+1, n, str+'R', vis, maze);
        dfs(i-1, j, n, str+'U', vis, maze);
        vis[i][j] = false;
    }
    
public:
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        // Your code goes here
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        string str = "";
        dfs(0, 0, n, str, vis, maze);
        
        // if(ans.size()==0) retu
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends