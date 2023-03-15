class Solution {
public:
    void fn(string &curr, int open, int close, int n, vector<string> &ans){
        if(close == n){
            ans.push_back(curr);
        }
        
        if(open < n){
            curr.push_back('(');
            fn(curr, open+1, close, n, ans);
            curr.pop_back();
        }
        if(close < open){
            curr.push_back(')');
            fn(curr, open, close+1, n, ans);
            curr.pop_back();
        }
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        fn(curr, 0, 0, n, ans);
        return ans;
    }
};