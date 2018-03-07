class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Computation: O(n)
        // space: O(n)
        unordered_map<int, int> m;
        m[0]=-1;
        int res =0, s = 0;
        for(int i=0; i< nums.size();++i){
            if(nums[i]==1) ++s;
            else           --s;
            
            if(m.find(s)==m.end())
                m[s]=i;
            else
                res = max(res, i-m[s]);
        }
        return res;
    }
};
