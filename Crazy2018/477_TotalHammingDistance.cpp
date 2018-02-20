class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        // computation: O(32n)
        // space: O(1)
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            // n digits, at each of the bit location, there are cnt1*(n-cnt1) distance 
            int cnt = 0;
            for (int num : nums) {
                if (num & (1 << i)) ++cnt;
            }
            res += cnt * (n - cnt);
        }
        return res;
    }
};