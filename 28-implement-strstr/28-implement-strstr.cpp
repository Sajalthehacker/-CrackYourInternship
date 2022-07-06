class Solution {
public:
    int strStr(string s, string x) {
        int n = s.length(), m = x.length(), ind = -1;
        for(int i=0; i<=n-m; i++){
            if(s[i] == x[0]){
                bool flag = true;
                for(int j=0; j<m; j++){
                    if(x[j] != s[i+j]){
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    ind = i;
                    break;
                }
            }
        }
        return ind;
    }
};