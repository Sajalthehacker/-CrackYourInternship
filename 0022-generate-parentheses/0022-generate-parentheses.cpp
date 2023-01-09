class Solution {
private:
    void fn(int index, int n, int open, int close, string &str, vector<string> &ans){
        if(index == 2*n) {
            ans.push_back(str);
            return;
        }
        if(open < n){
            str.push_back('(');
            fn(index+1, n, open+1, close, str, ans);
            str.pop_back();
        }
        if(close < open){
            str.push_back(')');
            fn(index+1, n, open, close+1, str, ans);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        fn(0, n, 0, 0, str, ans);
        return ans;
    }
};