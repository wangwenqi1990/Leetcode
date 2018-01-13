class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // O(min(m, n))
        int i = m-1, j=n-1, k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j])
                nums1[k--]=nums1[i--];
            else
                nums1[k--]=nums2[j--];
        }
        
        if(i<0){
            for(;j>=0;j--)
                nums1[j] = nums2[j]; 
        }
    }
};