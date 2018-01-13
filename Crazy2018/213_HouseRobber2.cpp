class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        return max(rob2(nums,1, n-1), rob2(nums, 0, n-2));
    }
    int rob2(vector<int>& nums, int left, int right){
        if(right==left)     return nums[left];
        if(right==left+1)   return max(nums[left], nums[right]);
        int dp[right-left+1]={0};
        dp[0]=nums[left];
        dp[1]=max(nums[left], nums[left+1]);
        for(int i=2; i<right-left+1;i++){
            dp[i]=max(dp[i-1], dp[i-2]+nums[left+i]);
        }
        return dp[right-left];
    }
};