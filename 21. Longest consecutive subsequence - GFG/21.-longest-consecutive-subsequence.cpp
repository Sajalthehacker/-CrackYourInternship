// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      unordered_set<int> m(arr,arr+n);
      int res=1;
      int temp = 1;
      int j = 1;
      for(int i=0; i<n; i++){
          if(m.count(arr[i]-1) == 0){
              while(m.count(arr[i]+j) == 1){
                  temp++;
                  j++;
              }
              res = std::max(res,temp);
              temp = 1;
              j = 1;
          }
      }
      return res;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends