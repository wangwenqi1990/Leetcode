class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Space: O(1)  Compuation: O(n^3)
        sort(nums.begin(), nums.end());
        int n= nums.size();
        vector<vector<int>> res;
        
        for(int i=0; i<n-3;){
            for(int j=i+1;j<n-2;){
                int t = target-nums[i]-nums[j];
                int l=j+1, r=n-1;
                
                while(l<r){
                    int lr = nums[l]+nums[r];
                    
                    if(lr==t){
                        vector<int> tp;
                        tp.push_back(nums[i]);
                        tp.push_back(nums[j]);
                        tp.push_back(nums[l]);
                        tp.push_back(nums[r]);
                        res.push_back(tp);
                        // avoid duplicate
                        r--;
                        while(nums[r]==nums[r+1]) r--;
                        l++;
                        while(nums[l]==nums[l-1]) l++;
                    }
                    else if(lr>t){
                        r--;
                        // faster
                        while(nums[r]==nums[r+1]) r--;
                    }
                    else{
                        l++;
                        while(nums[l]==nums[l-1])   l++;
                    }
                }
                j++;
                while(nums[j]==nums[j-1]) j++;
            }
            i++;
            while(nums[i]==nums[i-1]) i++;
        }
        return res;
    }
};