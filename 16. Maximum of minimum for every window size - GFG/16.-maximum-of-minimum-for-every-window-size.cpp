// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
       // Your code here
       stack<int> leftMin,rightMin;
       vector<int> leftMinPos(n+1,-1),rightMinPos(n+1,n);
       vector<int> ans(n+1,0);
       for(int i=0;i<n;i++){
 
           while(!leftMin.empty() && arr[leftMin.top()]>=arr[i]){
               leftMin.pop();
           }
           if(leftMin.empty())
               leftMinPos[i]=-1;
           else
               leftMinPos[i]=leftMin.top();
           leftMin.push(i);
       

           while(!rightMin.empty() && arr[rightMin.top()]>=arr[n-i-1]){
               rightMin.pop();
           }
           if(rightMin.empty())
               rightMinPos[n-i-1]=n;
           else rightMinPos[n-i-1]=rightMin.top();
       rightMin.push(n-i-1);
       }

   for(int i=0;i<n;i++){
       int pos = rightMinPos[i]-leftMinPos[i]-1;
       ans[pos] = max(ans[pos],arr[i]);
   }
   for(int i=n-1;i>=1;i--){
       ans[i]=max(ans[i],ans[i+1]);
   }
   vector<int> tmp;
   for(int i=1;i<=n;i++){
       tmp.push_back(ans[i]);
   }
   return tmp;
   // return ans;
   
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends