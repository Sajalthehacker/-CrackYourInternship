class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        // Implementation of next greater to right
        // monotinic stack
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<int> stt; // store indexes
        for(int i=n-1; i>=0; i--){
            while(!stt.empty() and temp[stt.top()] <= temp[i]) 
                stt.pop();
            
            if(!stt.empty())
                ans[i] = stt.top() - i;
            
            stt.push(i);
        }
        return ans;
    }
};