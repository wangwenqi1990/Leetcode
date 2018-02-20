class Solution {
public:
    int trap(vector<int>& height) {
        // Computation: O(n)
        // space: O(1)
        int res = 0, ml = 0, mr=0, n = height.size();
        vector<int> dp(n, 0);
        for(int i=0; i<n;++i){
            dp[i] = ml;             // maximum height for the left side of location i, not include i
            ml = max(ml, height[i]);
        }
        for(int i=n-1; i>=0; --i){
            dp[i] = min(dp[i], mr); // maximum height for the right side of location i, not include i, and get minimum
            mr = max(mr, height[i]);
            if(dp[i]>height[i])
                res += dp[i]-height[i];
        }
        return res;
    }
};