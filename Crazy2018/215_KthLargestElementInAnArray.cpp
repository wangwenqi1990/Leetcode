class Solution {
public:
    // solution 1: O(n) computation and O(min(k, n-k)) space
    int findKthLargest1(vector<int>& nums, int k) {
        // priority queue solution
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }
    
    
    // this solution saves memory cost, but is slow in computation
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            else if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
    // find a partation location r such that
    // in range [left, right], all entries on the left of r are >= nums[r],all entries on the right of r are <= nums[r]
    // O(right-left)
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && pivot < nums[r]) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) ++l;
            if (nums[r] <= pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    } 
};