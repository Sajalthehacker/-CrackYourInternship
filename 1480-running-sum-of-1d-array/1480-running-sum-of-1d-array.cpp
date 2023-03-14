class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> pref;
        int sum = 0;
        for(int it : nums) {
            sum += it;
            pref.push_back(sum);
        }
        return pref;
    }
};