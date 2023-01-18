class Solution {
public:
    bool isValid(string s) {
        vector<char> stt;
        for(int i=0; i<s.size(); i++){
            stt.push_back(s[i]);
            string curr = "";
            if(stt.size()>=3){
                for(int j = stt.size() - 3 ; j< stt.size(); j++)
                    curr.push_back(stt[j]);
                if(curr == "abc"){
                    for(int k=0; k<3; k++) stt.pop_back();
                }
                
            }
        }
        if(stt.size() == 0) return true;
        else return false;
    }
};