class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0, s = 0;
        unordered_map<int, int> m;
        m[0]=-1;
        for(int i=0; i< nums.size(); ++i){
            s += nums[i];
            if(s==k)                        res= i+1;// this line for sppeding up
            else if(m.find(s-k)!=m.end())   res = max(res, i-m[s-k]);
            if(m.find(s)==m.end())          m[s]=i;
        }
        return res;
    }
};
