class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=nums[0]+nums[1]+nums[2]; // initial value
        int n= nums.size();
        sort(nums.begin(), nums.end());  // nlogn
        
        int i=0;
        while(i< n-2){
            int l = i+1, r=n-1;
            int t = target - nums[i];
            
            while(l<r){
                int tp = nums[l] + nums[r];
                if(tp==t)
                    return target;
                else if(tp>t){
                    if(abs(res-target) >abs(nums[i]+tp-target))
                        res = nums[i]+tp;
                    r--;
                    while(l<r && nums[r]==nums[r+1])
                        r--;
                }
                else{
                    if(abs(res-target) >abs(nums[i]+tp-target))
                        res = nums[i]+tp;
                    l++;
                    while(l<r && nums[l]==nums[l-1])
                        l++;
                }
            }
            
            i++;
            while(i<n-2 && nums[i] == nums[i-1])
                i++;
        }
        return res;
    }
};