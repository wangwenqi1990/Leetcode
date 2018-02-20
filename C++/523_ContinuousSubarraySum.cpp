class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> st;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];                     // cumulative sum
            int t = (k == 0) ? sum : (sum % k); 
            if (st.count(t)) return true;
            st.insert(pre);                     // update the set
            pre = t;
        }
        return false;
    }
};