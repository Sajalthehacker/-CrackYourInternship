//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isValid(int i, int j, int n, vector<vector<int>>& mat){
        if(i<0 || j < 0 || i>=n || j >= n){
            return false;
        }
        return true;
    }
    
    bool fn(int i, int j, int n, vector<vector<int>> &path, vector<vector<int>>&mat){
        // cout << i << " " << j << "\n";
        if(i == n-1 && j == n-1){
            path[i][j] = 1;
            return 1;
        }
        if(i > n or j > n) return 0;
        path[i][j] = 1;
        for(int jump = 1; jump <= mat[i][j]; jump++){
            if(isValid(i, j+jump, n, mat)) {
                if(fn(i, j+jump, n, path, mat)) return 1;
            }
            if(isValid(i+jump, j, n, mat)) {
                if(fn(i+jump, j, n, path, mat)) return 1;
            }
        }
        path[i][j] = 0;
        return 0;
    }

	vector<vector<int>> ShortestDistance(vector<vector<int>>&mat){
	   // Code here
	   int n = mat.size();
	   vector<vector<int>> path(n, vector<int> (n, 0));
	   if (fn(0, 0, n, path, mat)) return path;
	   else return {{-1}};
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends