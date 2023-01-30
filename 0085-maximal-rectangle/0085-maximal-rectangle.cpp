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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<int> heights(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] != '0') heights[j] += 1;
                else heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};