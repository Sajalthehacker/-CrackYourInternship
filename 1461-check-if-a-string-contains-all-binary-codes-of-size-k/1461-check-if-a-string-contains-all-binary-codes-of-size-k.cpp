class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length(), cnt = 0;
        unordered_set<string> stt;
        for(int i=0; i<=n-k; i++){
            string temp = "";
            for(int j=i; j<i+k; j++){
                temp += s[j];
            }
            if(stt.find(temp)==stt.end()){
                cnt++;
                stt.insert(temp);
            }
        }
        
        if(cnt == pow(2, k)) return true;
        else return false;
    }
};