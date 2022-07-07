// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m = grid.size(); 
	    int n = grid[0].size(); 
	    vector<vector<int>> res(m, vector<int>(n, INT_MAX)); 
	    queue<pair<int, int>> q; 
	    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	    
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                if (grid[i][j] == 1){
                    q.push({i, j}); 
                    res[i][j] = 0; 
                }
        }	    
        while(!q.empty()){
            int x = q.front().first; 
            int y = q.front().second; 
            q.pop(); 
            
            for(auto &d: dir){
                int a = d[0] + x; 
                int b = d[1] + y;
                if (a >= 0 and b >= 0 and a < m and b < n){
                    if (res[a][b] > res[x][y] + 1){
                        res[a][b] = res[x][y] + 1; 
                        q.push({a, b}); 
                    }
                }
            }
        }
        return res; 
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends