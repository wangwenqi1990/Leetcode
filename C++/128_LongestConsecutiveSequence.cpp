class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        // O(n) to build a set
        unordered_set<int> s(nums.begin(), nums.end());
        // O(n) search: if existing, search left&right  and return the length 
        for (int val : nums) {
            if (!s.count(val)) continue;
            s.erase(val);
            int pre = val - 1, next = val + 1;
            while (s.count(pre)) s.erase(pre--);
            while (s.count(next)) s.erase(next++);
            res = max(res, next - pre - 1);
        }
        return res;
    }
};