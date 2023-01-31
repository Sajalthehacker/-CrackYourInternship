class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pque;
        for(int it : amount) pque.push(it);
        int ans = 0;
        while(pque.size() >= 2){
            int a = pque.top(); pque.pop();
            int b = pque.top(); pque.pop();
            if(a>0) a -= 1; else break;
            if(b>0) b -= 1;
            
            if(a>0) pque.push(a);
            if(b>0) pque.push(b);
            ans++;
        }
        if(pque.size() == 1) ans += pque.top();
        return ans;
    }
};