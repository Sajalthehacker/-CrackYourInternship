class Solution {
public:
    bool checkString(string s) {
        bool flag = false;
        for(char it : s){
            if(it == 'b') flag = true;
            if(flag && it == 'a') return false;
        }
        return true;
    }
};