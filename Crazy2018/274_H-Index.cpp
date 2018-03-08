class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(); if(n==0) return 0;
        // O(nlogn)
        sort(citations.begin(), citations.end());
        int l = 0, r=n-1;
        // max l s.t. nums[l] >= n-l
        // O(logn)
        while(l<r){
            int m = l + (r-l)/2;
            if(citations[m]>=n-m) r = m;
            else                  l = m +1;
        }
        return min(n-r, citations[r]);
    }
};
