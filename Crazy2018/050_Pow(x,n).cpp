class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        // this is fast since it considers the problem by considerint the binary representation of n
        for (int i = n; i != 0; i /= 2) {
            if (i % 2 != 0) res *= x;
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};
