// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    void solve(set<vector<int>> &us , vector<int> temp, vector<int> arr, int n, int k){
        us.insert(temp);
        if(k==n)
        return;  
        if(k<n){
            for(int i=k;i<n;i++){
            temp.push_back(arr[i]);
            solve(us, temp, arr, n, i+1);
            temp.pop_back();
            }
        }  
        return;
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        set<vector<int>> us;
        sort(arr.begin() , arr.end());
        vector<int> temp;
        solve(us, temp, arr, n, 0);
        vector<vector<int> > ans(us.begin(),us.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends