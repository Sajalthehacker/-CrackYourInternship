// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    public :
    bool check(int num){
        while(num){
            int temp = num%10;
            if(!(temp == 2 || temp ==3 || temp == 5 || temp == 7))
                return false;
            num = num/10;
        }
        return true;    
    }
    
    int count = 0;
    int num = 2;
    //Function to find nth number made of only prime digits.
    int primeDigits(int n)
    {
        while(count != n ){
            if(check(num)){
                count++;
            }
            num++;
        }
        
        return num-1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    // All the above tasks are preprocessing, now you can run testcases
    // and then print the values accordingly
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout << ob.primeDigits(n) << "\n";   
    }
}
  // } Driver Code Ends