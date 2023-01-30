class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pque;
        for(int it : arr){
            pque.push({abs(it - x), it});
            if(pque.size() > k) pque.pop();
        }
        vector<int> ans;
        while(!pque.empty()){
            ans.push_back(pque.top().second);
            pque.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};