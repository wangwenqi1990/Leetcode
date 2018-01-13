bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right){
            int mid = left+(right-left)/2;      // avoid data overflow
            if(isBadVersion(mid))   right = mid;
            else    left = mid+1;
        }
        return right;   // or left, since left = right in the end
    }
};