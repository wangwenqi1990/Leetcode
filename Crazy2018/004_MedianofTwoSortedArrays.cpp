class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        if ( (l1+l2)%2 == 1 )
            return findMedian2(nums1, nums2, (l1+l2)/2+1);
        else
            return 0.5*(findMedian2(nums1, nums2, (l1+l2)/2) + findMedian2(nums1, nums2, (l1+l2)/2+1));
    }
    
    // find the kth(not index but rank) from two arrays
    int findMedian2(vector<int>& nums1, vector<int>& nums2, int k){
        int l1 = nums1.size(), l2 = nums2.size();
        // l2 has to be longer
        if (l1 > l2) 
            return findMedian2(nums2, nums1, k);
        
        int left=0, right=l1;
        // min  left
        // s.t. nums1[left] >= nums2[k-1-left]
        // Note: 
        // (1) left =0; right =m (not m-1)
        // (2) right= mid or left = mid+1;
        while(left < right){
            int mid = left + (right-left)/2;
            int tp = k-1-mid;
            if(0<= tp && tp < l2 & nums1[mid] >= nums2[tp])
                right = mid;
            else
                left = mid +1;
        }
        // (left) + (k-left) = k
        int c1 = left-1>=0? nums1[left-1]:numeric_limits<int>::min();
        int tp = k-1-left;
        int c2 = tp>=0? nums2[tp]:numeric_limits<int>::min();
        return max(c1, c2);    
    }
};