// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<long long int>b(n,0),f(n,0);
       b[0]=arr[0];
       f[n-1]=arr[n-1];
       for(int i=1; i<n; i++){
           if(b[i-1]>arr[i]){
               b[i]=b[i-1];
           }
           else{
               b[i]=arr[i];
           }
       }
       
       for(int i=n-2; i>=0; i--){
           if(f[i+1]>arr[i]){
               f[i]=f[i+1];
           }
           else{
               f[i]=arr[i];
           }
       }
       
       long long int ans=0;
       for(int i=0; i<n; i++){
           long long maxi= min(b[i],f[i]);
           ans+= abs(arr[i]-maxi);
       }
       return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends