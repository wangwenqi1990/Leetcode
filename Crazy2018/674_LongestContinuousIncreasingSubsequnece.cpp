class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), res = 0, start=0, cnt=1;
        if(n==0) return 0;
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]) ++cnt;
            else{
                res = max(i-start, res);
                start = i;
                cnt=1;
            }
        }
        return max(res, n-start);
    }
};