class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // harsh-tabl
        // computation: O(n) space: O(n)
        unordered_map<int, int> m{{0,-1}};
        int s = 0, n = nums.size();
        for(int i=0; i<n; ++i){
            s+=nums[i];
            int t = k==0? s : s%k;
            if(m.count(t)){
                if(i-m[t]>1) return true;
            }
            else
                m[t]=i;
        }
        return false;
    }
};
