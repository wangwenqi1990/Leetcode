class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        int hold[n]={0}, sold[n]={0};
        // hold[i]: till step i, the free money includes with a open position (open position does not include)
        // sold[i]: till step i, the free money includes without open positions.
        hold[0]=-prices[0];             
        sold[1]=max(hold[0]+prices[1], sold[0]);
        hold[1]=max(-prices[0], -prices[1]);
        for(int i=2; i<n; i++){
            sold[i]=max(hold[i-1]+prices[i], sold[i-1]);
            hold[i]=max(hold[i-1],sold[i-2]-prices[i]);
        }
        return sold[n-1];
    }
};