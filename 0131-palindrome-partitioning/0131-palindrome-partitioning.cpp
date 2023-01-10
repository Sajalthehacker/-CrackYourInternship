class Solution {
public:
    void fn(int ind, string s, vector<string> &path, vector<vector<string>> &ans){
        if(ind == s.size()){
            ans.push_back(path);
            return;
        }
        
        for(int i=ind; i < s.size(); i++){
            if(isPallindrome(s, ind, i)){
                path.push_back(s.substr(ind, i - ind +1));
                fn(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }
    
    bool isPallindrome(string str, int start, int end){
        while(start <= end){
            if(str[start++] != str[end--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        fn(0, s, path, ans);
        return ans;
    }
};