// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
   {
   unsigned int ans = 0, cur = 0, b1, b2;
    while(n){
      b1 = n&1;
      n >>= 1;
      b2 = n&1;
      n >>= 1;
      ans += (b1*pow(2, cur+1) + b2*pow(2, cur));
      cur += 2;
    }
    return ans;
   }
};

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}  // } Driver Code Ends