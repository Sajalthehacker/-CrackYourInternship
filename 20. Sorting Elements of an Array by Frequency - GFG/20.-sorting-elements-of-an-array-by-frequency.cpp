// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
  static bool mycmp(pair<int, int> p1, pair<int, int> p2){
       if(p1.second == p2.second)              
           return p1.first < p2.first;
       return p1.second > p2.second;           
   }
   
   vector<int> sortByFreq(int a[],int n){
       vector<int> vect;
       unordered_map<int, int> map;
       for(int i = 0; i < n; i++){
           map[a[i]]++;
       }
       vector<pair<int, int>> vec(map.begin(), map.end());    
       sort(vec.begin(), vec.end(), mycmp);
       for(auto e : vec){
           for(int i=0;i<e.second;i++)
               vect.push_back(e.first);
       }
       return vect;
   }
};


// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends