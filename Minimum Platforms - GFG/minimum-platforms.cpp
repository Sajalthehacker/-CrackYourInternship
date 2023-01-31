//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool compp(pair<int, int> &p1, pair<int, int> &p2){
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    }
    int findPlatform(int arr[], int dep[], int n) {
    	// Your code here
    	vector<pair<int, int>> changes;
    	for(int i=0; i<n; i++) changes.push_back({arr[i], 1});
    	for(int i=0; i<n; i++) changes.push_back({dep[i], -1});
    	sort(changes.begin(), changes.end(), compp);
    	int ans = 0, curr = 0;
    	for(auto it : changes){
    	    curr += it.second;
    	    ans = max(ans , curr);
    	}
    	return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends