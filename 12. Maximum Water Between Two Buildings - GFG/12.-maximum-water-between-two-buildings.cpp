// { Driver Code Starts
//Initial Template for C++


// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to return the maximum water that can be stored.
    int maxWater(int height[], int n) { 
        int max_water=0, cur_water=0, first=0,last=n-1;
        while(first + 1 < last) {
            cur_water = min(height[first], height[last]) * (last - first - 1);
            max_water = max(max_water, cur_water);
            if(height[first] < height[last]) first++;
            else last--;
        }
        return max_water;
    } 
};



// { Driver Code Starts.

// Driver code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int height[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>height[i];
        }
        Solution ob;
        cout<<(ob.maxWater(height, n))<<endl;
    }

	 
} 

  // } Driver Code Ends