class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> stt;
        string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                            ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                            "...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(string word : words){
            string code = "";
            for(char it : word){
                code += morse[it - 'a'];
            }
            stt.insert(code);
        }
        return stt.size();
        
    }
};