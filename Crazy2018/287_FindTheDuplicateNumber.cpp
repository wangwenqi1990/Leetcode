class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // similar to 142 Linked List Cycle II
        // Computation: O(n)
        // Space: O(1)
        int s = nums[0];
        int f = nums[s];
        while(s!=f){
            s=nums[s];
            f=nums[nums[f]];
        }
        f=0;
        while(s!=f){
            s=nums[s];
            f=nums[f];
        }
        return s;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // fact: n should have n numbers less or euqal to it
        int n = nums.size();
        int right = n, left = 1;
        
        while(left < right){
            int mid = left + 0.5 *(right-left);
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(nums[i]<=mid) cnt++;
            }
            if(cnt<=mid) left = mid+1;
            else right = mid;
        }
        return left;
    }
};
