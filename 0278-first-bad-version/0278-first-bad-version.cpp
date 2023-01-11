// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
//         if(n == 1) {
//             if(isBadVersion(1)) return 1;
            
//         }
        int l = 1, r = n, m;
        while(r-l >= 1){
            m = l + (r - l)/2;
            if(isBadVersion(m)){
                r = m;
            }
            else l = m+1;
        }
        if(isBadVersion(l)) return l;
        else if(isBadVersion(r)) return r;
        else return -1;
        
    }
};