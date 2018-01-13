class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // space: O(n), compuatation: O(n)
        vector<int> res;
        int n = nums.size();
        if(n==0) return res;
        
        // f is of size n
        vector<int> f; f.push_back(1);
        for(int i=0; i< n-1; i++)
            f.push_back(f.back() * nums[i]);
        
        // e is of size n
        vector<int> e; e.push_back(1);
        for(int i= n-1; i> 0;i--)
            e.push_back(e.back() * nums[i]);
        
        for(int i= 0; i< n; i++)
            res.push_back(f[i] *e[n-i-1]);
        
        return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // space is more efficient
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};