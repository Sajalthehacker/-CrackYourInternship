// { Driver Code Starts
//Initial Template for C++

// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <bits/stdc++.h> 

using namespace std;


 // } Driver Code Ends
//User function Template for C++


//Function to fill lps[] for given patttern pat[0..M-1].
//Function to check if the pattern exists in the string or not.
bool KMPSearch(string pat, string txt) 
{
    // Your code here
    int f=txt.find(pat);
    if(f==-1)
    {
        return false;
    }
    return true;
    
}

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{ 
    int t;
    std::cin >> t;
    
    while(t--){
        string s, pat;
        cin >> s >> pat;
        if(KMPSearch(pat, s)){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    
	return 0;
} 
  // } Driver Code Ends