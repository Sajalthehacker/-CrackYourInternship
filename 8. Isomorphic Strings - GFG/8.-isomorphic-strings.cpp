// { Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
       if(str1.length() != str2.length()) 
        {
            return false;
        }
    
        int a[26] = {0};
        int b[26] = {0};
    
        for(int i=0;i<str2.length();i++) 
        {
            if(b[str2[i]-'a'] == 0 && a[str1[i]-'a'] == 0) 
            {
                b[str2[i]-'a'] = str1[i];
                a[str1[i]-'a'] = str2[i];
            
            } 
            else 
            {
                if(b[str2[i]-'a'] == str1[i] && a[str1[i] - 'a'] == str2[i]) 
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends