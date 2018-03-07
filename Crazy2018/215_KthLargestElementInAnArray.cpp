class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // quick sort approach
        // computation: O(nlog(n))   space: O(1)
        int left = 0, right = nums.size()-1;
        while(1){
            int pos = partition(nums, left, right);
            if(pos==k-1)        return nums[pos];
            else if(pos>k-1)    right = pos-1;
            else                left  = pos+1;
        }
    }
    // find a partition r such that [left, r] are greater or equal to p;
    int partition(vector<int>& nums, int left, int right){
        int p = nums[left], l=left+1, r= right;
        while(l<=r){
            if(nums[l]<p && p < nums[r])    {swap(nums[l++], nums[r--]);}
            if(nums[l]>=p)  ++l;
            if(nums[r]<=p)  --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};

class Solution {
public:
    // Priority queue with fixed length k
    // computation: O(nlogk)  space: O(k)
    int findKthLargest(vector<int>& nums, int k) {
        // last term not included, total k entries
        priority_queue<int , vector<int>, greater<int> > q (nums.begin(), nums.begin()+k);
        for(int i=k; i< nums.size(); ++i){
            q.push(nums[i]); q.pop();
        }
        return q.top();
    }
};
