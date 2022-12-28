class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pque;
        double total = 0, curr = 0;
        for(int it : nums) {
            total += (double)it*(1.0);
            pque.push((double)it*(1.0));
        }
        int ops = 0;
        while(curr < total*(1.0)/2){
            ops++;
            double ele = pque.top();
            pque.pop();
            curr += (ele*(1.0)/2);
            pque.push(ele*(1.0)/2);
        }
        return ops;
    }
};