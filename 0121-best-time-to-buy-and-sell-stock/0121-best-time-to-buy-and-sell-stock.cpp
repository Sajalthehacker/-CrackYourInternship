class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevMin = prices[0], maxP = 0;
        for(int it : prices){
            if(it < prevMin) prevMin = it;
            else maxP = max(maxP, it - prevMin);
        }
        return maxP;
    }
};