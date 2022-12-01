class Solution {
private:
    int helper(int i, int j, string s){
        int cnt = 0;
        for(int x = i; x <j; x++){
            if(s[x] == 'a'|| s[x] == 'e'|| s[x] == 'i'|| s[x] == 'o'|| s[x] == 'u'|| 
               s[x] == 'A'|| s[x] == 'E'|| s[x] == 'I'|| s[x] == 'O'|| s[x] == 'U') cnt++;
        }
        return cnt;
    }
public:
    bool halvesAreAlike(string s) {
        return helper(0, s.size()/2, s) == helper(s.size()/2, s.size(), s);
    }
};