class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int cntA = 0, cntB = 0;
        for(char it : s) 
            if(it == 'a') cntA++;
        // if we delete all a's the final string is balances( i.e. "bbbb...b")
        int ans = cntA; // dleteing all the a's 
        
        // Now we are looking for a split where all the left b's are deleted 
        // and all the right a's are deleted string end up as ("aaa...aabbb..bbb")
        for(char it : s){
            if(it == 'a') cntA--; // we arent deleting this paticular 'a'
            else cntB++; // we are deleting 'b', coz we dont want any b sitting in left side
            ans = min(ans, cntA+cntB);
        }
        
        return ans;
    }
};