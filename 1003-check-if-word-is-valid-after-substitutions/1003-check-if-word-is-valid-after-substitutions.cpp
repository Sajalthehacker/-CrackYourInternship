class Solution {
public:
    bool isValid(string s) {
        stack<char> stt;
        for(int i=0; i<s.size(); i++){
            stt.push(s[i]);
            if(stt.size() >= 3){
                char c1, c2, c3;
                c1 = stt.top(); stt.pop();
                c2 = stt.top(); stt.pop();
                c3 = stt.top(); stt.pop();
                if(!(c1 == 'c' && c2 == 'b' && c3 == 'a')){
                    stt.push(c3); stt.push(c2); stt.push(c1);
                }
            }
            
        }
        if(stt.empty()) return true;
        else return false;
    }
};