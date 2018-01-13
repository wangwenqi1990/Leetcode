class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // dp: continuty is controlled by res=max(res, large[i])
        int n = nums.size(), res=nums[0];
        int large[n]={0}, small[n]={0};
        large[0]=nums[0];
        small[0]=nums[0];
        for(int i=1;i<n; i++){
            // continus update or restart
            large[i]=max(max(large[i-1]*nums[i], small[i-1]*nums[i]), nums[i]); 
            small[i]=min(min(large[i-1]*nums[i], small[i-1]*nums[i]), nums[i]);
            res = max(res, large[i]);
        }
        return res;
    }
};