class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold[n]={-prices[0]};   // maximum free cash to time i with positions
        int sold[n]={0};            // maximum free cash to time i without positions
        for(int i=1; i<n; ++i){
            hold[i] = max(hold[i-1], sold[i-1]-prices[i]);  // assuming no transanction cost when buy
            sold[i] = max(sold[i-1], hold[i-1]+prices[i]-fee);
        }
        return sold[n-1];
    }
};
