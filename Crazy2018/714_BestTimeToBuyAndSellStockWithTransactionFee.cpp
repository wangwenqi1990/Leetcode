class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // sold[i] till step i, the free money without any position
        // hold[i] till step i, the free money with a position (free money does not include the position)
        int n = prices.size();
        int hold[n]={0}, sold[n]={0};
        hold[0]=-prices[0];
        for(int i=1; i<n;i++){
            sold[i]=max(sold[i-1], hold[i-1]+prices[i]-fee);
            hold[i]=max(hold[i-1], sold[i-1]-prices[i]);
        }
        return sold[n-1];
    }
};