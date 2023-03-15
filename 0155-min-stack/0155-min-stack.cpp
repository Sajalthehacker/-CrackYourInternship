class MinStack {
private:
    stack<pair<int, int>> stt; // <element, minEle>
public:
    MinStack() {
        // already initialised globally
    }
    
    void push(int val) {
        if(stt.empty()) stt.push({val, val});
        else{
            int mini = min(val, stt.top().second);
            stt.push({val, mini});
        }
    }
    
    void pop() { 
        stt.pop();
    }
    
    int top() {
        return stt.top().first;
    }
    
    int getMin() {
        return stt.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */