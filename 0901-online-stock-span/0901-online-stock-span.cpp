class StockSpanner {
public:
    
    stack<pair<int,int>> stt;
    StockSpanner() {
         
    }
    
    int next(int price) {
        int currSpan = 1;
        while(!stt.empty() && stt.top().first <= price) {
            currSpan += stt.top().second;
            stt.pop();
        }
        
        stt.push({price, currSpan});
        return currSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */