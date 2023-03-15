class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> stt;
        for(int it : asteroids){
            if(it < 0){
                if(stt.empty() || (stt.top() < 0)) stt.push(it);
                else{
                    while(!stt.empty() && stt.top() > 0 && stt.top() < abs(it))
                        stt.pop();
                    if(!stt.empty()){
                        if(stt.top() == abs(it)) stt.pop();
                        else if(stt.top() < abs(it)) stt.push(it);
                    } 
                    else stt.push(it);
                }
            }
            else stt.push(it);
        }
        while(stt.size()) {
            ans.push_back(stt.top());
            stt.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};