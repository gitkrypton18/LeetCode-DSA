class StockSpanner {
    vector<int> prices;

public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        int j=prices.size()-1;
        int cnt=0;
        while(j>=0){
            if(prices[j]<=price) cnt++;
            else break;
            j--;
        }
        return cnt;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */