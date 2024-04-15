class StockSpanner {
public:
    vector<int> prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        prices.push_back(price);
        int n = prices.size();
        int i =0;
        for(i=n-1;i>=0;i--){
            if(prices[i] > price){
                cnt = n-i-1;
                break;
            }
        }
        if(i == -1) return n;
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */