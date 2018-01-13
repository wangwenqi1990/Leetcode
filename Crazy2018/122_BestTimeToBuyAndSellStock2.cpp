class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // computation: O(n) space: O(1)
        int res = 0, l=0, r=1, n=prices.size();
        if(n<=1) return res;
        while(1){
            while(r<n && prices[r]>=prices[r-1])
                r++;
            res += prices[r-1] - prices[l];
            if(r==n) break;
            l = r++;                        // update buy and sell time
        }
        return res;
    }
};