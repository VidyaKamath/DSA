class StockSpanner {
public:
    
    stack<pair<int, int>> s;
    int idx;

    StockSpanner() {  
       idx=0;   
    }
    
    int next(int price) {

        //Find the nearest greater to left element. Pop the 
        // elements 
        while(s.size()!=0 && s.top().first <= price){
            s.pop();
        }
        
        //default value of the idx i.e if nearest greater to left element is not found.
        int ngl_idx = -1;
        if(s.size()!=0 && s.top().first > price){
            // nearest greater to left element is found. store its index 
            ngl_idx = s.top().second;
        }
       
        //store the price with its index. e.g. (100, 0)
        s.push({price, idx});
        int span = idx - ngl_idx;
        idx++;

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
