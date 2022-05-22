class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        for(int i=0; i<n; i++){
            int l=i, r=i;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    cnt++;
                }else break;
                l--;
                r++;
            }
        }
        for(int i=0; i<n-1; i++){
            int l=i, r=i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    cnt++;
                }else break;
                l--;
                r++;
            }
        }
        
        return cnt;
    }
};