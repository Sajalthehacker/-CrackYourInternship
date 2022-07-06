// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
   {
       // Your code here
       int res=INT_MAX;
       vector<int>v1;
       for(int i=0;i<patt.length();i++)
       {
           int p=str.find(patt[i]);
           v1.push_back(p);
       }
       int min=INT_MAX;
       for(int i=0;i<v1.size();i++)
       {
           if(min>v1[i]&&v1[i]!=-1)
           min=v1[i];
       }
       if(min==INT_MAX)
       return -1;
       return min;
       
   }
};

// { Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}
  // } Driver Code Ends