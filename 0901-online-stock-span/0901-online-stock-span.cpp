class StockSpanner {
public:
    // Editorial : https://www.youtube.com/watch?v=slYh0ZNEqSw&t=801s
    stack<pair<int,int>> stt;
    StockSpanner() {
        // already initialised globally   
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