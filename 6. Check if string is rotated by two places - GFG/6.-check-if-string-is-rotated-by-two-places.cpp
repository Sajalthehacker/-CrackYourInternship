// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if(str1.length() != str2.length())
            return false;

        if(str1.length() <= 2 && str1.compare(str2) == 0)
            return true;
    
        if(str1.length() <= 2 && str1.compare(str2) != 0)
            return false;
    
        int i = str1.length();
    
        string sol1 = "";
        sol1 += str1.substr(i-2, 2) + str1.substr(0,i-2);
    
        string sol2 = "";
        sol2 += str1.substr(2, i-2) + str1.substr(0,2);
    
        return (str2.compare(sol1) == 0 || str2.compare(sol2) == 0);
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends