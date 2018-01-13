class Solution {
public:
    int numWays(int n, int k) {
        if(n<1 || k <1) return 0;
        int same = 0, different=k;  // the last two coloses are same or different
        for(int i=2; i<=n; i++){
            int tp = different;
            different = (same + different) * (k-1);
            same = tp;
        }
        return same+different;
    }
};