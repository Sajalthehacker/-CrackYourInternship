class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl(n, -1);
        vector<int> nsr(n, n);
        // get nsl of ind
        stack<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if(!s.empty()) nsl[i] = s.top();
            s.push(i);
        }
        
        // get nsr of ind
        stack<int> t;
        for(int i=n-1; i>=0; i--){
            while(!t.empty() && heights[t.top()] >= heights[i]) t.pop();
            if(!t.empty()) nsr[i] = t.top();
            t.push(i);
        }
        int area = 0;
        for(int i=0; i<n; i++){
            int h = heights[i];
            int w = nsr[i] - nsl[i] - 1;
            area = max(area, h*w);
        }
        return area;
    }
};