// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int *a, int books, int students) {
    int high = 0;
    int low = 0;
    for (int i = 0; i < books; ++i) {
        high += a[i];
        low = max(low, a[i]);
    }

    int ans = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        
        if (isFeasible(a, books, students, mid)) {
            high = mid - 1;
            ans = mid;
        }
        
        else
            low = mid + 1;
    }

    return ans;
}

bool isFeasible(int *a, int books, int students, int limit) {
    int pages = 0;
    int parts = 1;

    for (int i = 0; i < books; ++i) {
        if (pages + a[i] > limit) {
            parts++;
            pages = 0;
        }
        pages += a[i];
    }

    return (parts <= students);
}
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends