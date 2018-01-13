class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        // BuyAndSellStock2
        if(k>=n){
            int res = 0;
            for(int i=1; i<n; i++){
                int tp = prices[i]-prices[i-1];
                res+= tp>0? tp: 0;
            }
            return res;
        }
        // BuyAndSellStock3
        int g[k+1]={0};
        int l[k+1]={0};
        for(int i=1; i<n; i++){
            int diff = prices[i]-prices[i-1];
            // reverse order is tricky, why reverse??
            for(int j=k; j>=1; j--){
                l[j] = max(g[j-1]+max(diff, 0), l[j]+diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
};