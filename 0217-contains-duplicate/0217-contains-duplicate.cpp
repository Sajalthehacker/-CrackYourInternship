class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> stt;
        for(int it : nums) 
            if(stt.find(it) == stt.end()) stt.insert(it); 
            else return true;
        return false;
    }
};