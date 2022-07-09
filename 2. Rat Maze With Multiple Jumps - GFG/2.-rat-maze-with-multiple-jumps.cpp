// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends



//Function to find the minimum number of Hops required for the rat to 
//reach from the source block to the destination block. 
bool isValid (vector <int> maze[], int n, int i, int j)
{
    if (i<0 || j<0 || i>=n || j>=n || maze[i][j]==0)
        return false;
    return true;
}

bool helper (vector <int> maze[], vector<int> result[], int i, int j, int n)
{
    if (i==n-1 && j==n-1)
    {
        result[i][j]=1;
        return true;
    }
    
    if (isValid(maze, n, i, j))
    {
        result[i][j] = 1;
        
        int maxjumps = maze[i][j];
        
        for (int k=1; k<=maxjumps; k++)
        {
            if (helper(maze, result, i, j+k, n)==true)
                return true;
            if (helper(maze, result, i+k, j, n)==true)
                return true;
        }
        
        result[i][j]=0;
        return false;
    }
    
    return false;
}

void solve(int n, vector<int> maze[]) 
{
    vector <int> result[n];
    
    for (int i=0; i<n; i++)
    {
        vector <int> temp(n,0);
        result[i]=temp;
    }
    
    if (helper(maze, result, 0,0, n)==true)
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    
    cout << "-1\n";
    return;
}