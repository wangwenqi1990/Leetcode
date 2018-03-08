class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // computation: O(n^2) space: O(n)
        int res = 0, n = nums.size(), mx=0;
        vector<int> len(n, 1), cnt(n, 1);// the maximum length till ith entry; the maimum occurance till ith entry;
        for(int i=0; i< n; ++i){
            for(int j= 0; j<i; ++j){
                if(nums[i]<= nums[j])        continue;  // equal is the same as less, if considering updating entries for len[i]/cnt[i] for index less than j
                else{
                    if(len[i]==len[j]+1)    {cnt[i]+=cnt[j];}
                    else if(len[i]<len[j]+1){len[i]=len[j]+1; cnt[i] =cnt[j];}
                }
            }
            if (mx==len[i])             {res+=cnt[i];}
            else if (mx<len[i])         {mx=len[i]; res = cnt[i];}
        }
        return res;
    }
};
