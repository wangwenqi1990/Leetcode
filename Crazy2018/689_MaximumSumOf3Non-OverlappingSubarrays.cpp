class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), maxsum = 0;
        vector<int> sum = {0}, posLeft(n, 0), posRight(n, n-k), ans(3, 0);
        // the sum to the left
        for (int i:nums) sum.push_back(sum.back()+i);       
        // tot: the value the maximum K entries sum till for substring [0, i];
        // posLeft[i]: subarray from [i-k+1] to [i], the maximum start location. 
        for (int i = k, tot = sum[k]-sum[0]; i < n; i++) {
            if (sum[i+1]-sum[i+1-k] > tot) {
                posLeft[i] = i+1-k;
                tot = sum[i+1]-sum[i+1-k];
            }
            else 
                posLeft[i] = posLeft[i-1];
        }
        // tot: the value the maximum K entries sum till for substring [i, n];
        // posRight[i]: subarray from [i] to [i+k], the maximum start location.
        for (int i = n-k-1, tot = sum[n]-sum[n-k]; i >= 0; i--) {
            if (sum[i+k]-sum[i] >= tot) {
                posRight[i] = i;
                tot = sum[i+k]-sum[i];
            }
            else
                posRight[i] = posRight[i+1];
        }
        // switch window [i,i+k-1] for i=k,..., n-2k 
        // l is the maximum index to the left tail
        // r is the maximum index to the right tail
        for (int i = k; i <= n-2*k; i++) {
            int l = posLeft[i-1], r = posRight[i+k];
            int tot = (sum[i+k]-sum[i]) + (sum[l+k]-sum[l]) + (sum[r+k]-sum[r]);
            if (tot > maxsum) {
                maxsum = tot;
                ans = {l, i, r};
            }
        }
        return ans;
    }
};