class Solution {
public:
    static bool compp(int &i, int &j){
        string s = to_string(i), t = to_string(j);
        string op1 = s + t, op2 = t + s;
        return op1 > op2;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compp);
        string ans = "";
        for(int it : nums){
            ans += to_string(it);
        }
        for(char it : ans){
            if(it != '0') return ans;
        }
        return "0";
    }
};