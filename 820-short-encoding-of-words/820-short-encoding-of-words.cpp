class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s1(words.begin(), words.end()); // for storing uniques suffixes
        set<string> s2(words.begin(), words.end()); // final set after removing suffixes
        
        for(auto it : s1){
            for(int i=1; i<it.size(); i++){
                s2.erase(it.substr(i));
            }
        }
        int ans = 0;
        for(auto it : s2){
            ans += it.size()+1;
        }
        return ans;

    }
};