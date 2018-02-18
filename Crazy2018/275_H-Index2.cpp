class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n-1;
        // min i s.t. n-i >= citations[i]
        // this equal is important
        while(left <= right){   
            int mid = left + (right-left)/2;
            if(n-mid ==citations[mid])
                return n-mid;
            else if(n-mid <citations[mid])
                right = mid-1;
            else
                left = mid+1;
        }
        return  n-left;
    }
};