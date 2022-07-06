// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
        string smallestWindow (string s, string p)
    {
        int c=0,size=p.size();
        if(size>s.size()){
            return "-1";
        }
     int parr[26]={0},sarr[26]={0};
     for(int i=0;i<p.size();i++){
         parr[p[i]-'a']++;
     }
     int start=0,sand=-1,minlen=INT_MAX,len=0;
     for(int i=0;i<s.size();i++){
         sarr[s[i]-'a']++;
         if(sarr[s[i]-'a']<=parr[s[i]-'a'] && parr[s[i]-'a']!=0){
             c++;
         }
         if(c==size){
             while(sarr[s[start]-'a']>parr[s[start]-'a'] ||parr[s[start]-'a']==0){
                 sarr[s[start]-'a']--;
                 start++;
             }
             len=i-start+1;
             if(len<minlen){
                 sand=start;
                 minlen=len;
             }
         }
         
     }
     if(sand==-1){
         return "-1";
     }
     else{
         return s.substr(sand,minlen);
     }
    }

};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends