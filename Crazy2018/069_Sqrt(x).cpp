class Solution {
public:
    int mySqrt(int x) {
        // check mid if mid**2 > x;
        // if yes, right-1;
        // if not, left +1;
        // such that finally right**2 <= x for sure, left**2 >= x
        int left = 0, right = x/2+1;         // right*right > x
        while(left<=right){
            long long mid = (left+right)/2; // long long
            long long tp = mid * mid;       // long long
            if(tp==x)       return mid;
            else if(tp<x)   left = mid+1;
            else            right= mid-1;
        }
        return right;
    }
};