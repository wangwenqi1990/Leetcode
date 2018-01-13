class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        const int k = 3;    // 2+1
        int g[n][k]={0};    // g[i][j]: from the step 1 to step i, finish j transaction and the profit is maximum
        int l[n][k]={0};    // l[i][j]: from the step 1 to step i, finish j transaction and the last transaction at step i, such that profit is maximum
        for(int i=1; i<n; i++){
            int diff = prices[i]-prices[i-1];
            for(int j=1; j<k; j++){
                // term 1: i-1 step finish j-1 transaction, at step i, buy or not
                // term 2: l[i][j] is equivalent to l[i-1][j] and hold the last transition till i
                l[i][j] = max(g[i-1][j-1]+max(diff, 0), l[i-1][j]+diff);
                g[i][j] = max(g[i-1][j], l[i][j]);
            }
        }
        return g[n-1][2];
    }
};