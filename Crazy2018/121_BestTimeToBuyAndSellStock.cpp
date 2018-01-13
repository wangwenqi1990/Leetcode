class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // computation: O(n) space: O(1)
        int n= prices.size(), res = 0, l = 0, r=1;
        if(n<=1) return res;
        while(1){
            while(r<n && prices[r]>=prices[r-1])    // update sell time
                r++;
            res = max(res, prices[r-1]-prices[l]);
            if(r==n) break;
            l = prices[l] < prices[r]? l : r;       // update buy time
            r++;                                    
        }
        return res;
    }
};