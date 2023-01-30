class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> stt;
        vector<int> ngr(n, 0);
        for(int i=n-1; i>=0; i--){
            int cnt = 0;
            while(!stt.empty() && stt.top() < heights[i]){
                stt.pop();
                cnt++;
            }
            // There is an another tower to look in the right, if stack is not empty
            if(!stt.empty()) cnt++; 
            ngr[i] = cnt;
            stt.push(heights[i]);
            
        }
        ngr[n-1] = 0;
        return ngr;
    }
};