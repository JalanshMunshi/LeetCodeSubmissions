class StockSpanner {
public:
    stack<int> prices, span;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int t = 1;
        while(!prices.empty() && prices.top() <= price)
        {
            prices.pop();
            t += span.top();
            span.pop();
        }
        prices.push(price);
        span.push(t);
        return t;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */