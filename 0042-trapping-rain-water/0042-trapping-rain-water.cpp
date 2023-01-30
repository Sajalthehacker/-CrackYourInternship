class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // we consider how much amount of water every block contributes
        // next greater to right
        // stack<int> s;
        int ngr[n];
        for(int i=n-1; i>=0; i--){
            // while(!s.empty() && s.top() <= height[i]) s.pop();
            // if(s.empty()) ngr[i] = -1;
            // else ngr[i] = s.top();
            // s.push(height[i]);
            if(i == n-1) ngr[i] = height[i];
            else ngr[i] = max(ngr[i+1], height[i]);
        }
        // next greater to left
        stack<int> t;
        int ngl[n];
        for(int i=0; i<n; i++){
            // while(!t.empty() && t.top() <= height[i]) t.pop();
            // if(t.empty()) ngl[i] = -1;
            // else ngl[i] = t.top();
            // t.push(height[i]);
            if(i == 0) ngl[i] = height[0];
            else ngl[i] = max(ngl[i-1], height[i]);
        }
        
        int total = 0;
        for(int i=0; i<n; i++){
            // cout << ngl[i] << " " << ngr[i] << endl;
            if(ngr[i] == -1 || ngl[i] == -1) continue;
            total += min(ngl[i], ngr[i])-height[i];
        }
        return total;
        
    }
};