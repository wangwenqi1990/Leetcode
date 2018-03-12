class Solution {
public:
    int numDecodings(string s) {
        // computation: O(n), space O(n)
        int n = s.size(), M = 1e9 + 7;
        vector<long> dp(n + 1, 0);
        dp[0] = 1;
        if (s[0] == '0') return 0;
        dp[1] = (s[0] == '*') ? 9 : 1;
        for (int i = 2; i <= n; ++i) {
            // current is '0'
            if (s[i - 1] == '0') {
                if (s[i - 2] == '1' || s[i - 2] == '2') {dp[i] += dp[i - 2];}       // previous is '1' or '2'
                else if (s[i - 2] == '*')               {dp[i] += 2 * dp[i - 2];}   // previous is '*'
                else                                    {return 0;}                 // else
            } 
            // current is '1'-'9'
            else if (s[i - 1] >= '1' && s[i - 1] <= '9') {
                dp[i] += dp[i - 1];                                                                     // stand-alone
                if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {dp[i] += dp[i - 2];}      // previous is '1'-'9'
                else if (s[i - 2] == '*') {dp[i] += (s[i - 1] <= '6') ? (2 * dp[i - 2]) : dp[i - 2];}   // previous is '*'
            } 
            // current is '*'
            else {
                dp[i] += 9 * dp[i - 1];                             // stand-alone
                if (s[i - 2] == '1')        dp[i] += 9 * dp[i - 2]; // combine with 1 previous *
                else if (s[i - 2] == '2')   dp[i] += 6 * dp[i - 2];
                else if (s[i - 2] == '*')   dp[i] += 15 * dp[i - 2];
            }
            dp[i] %= M;
        }
        return dp[n];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        // computation:O(n), space: O(1) 
        // e0: possibilities if current stand-alone
        // e1: possibilities if previous number is 1 and current combined with previous number
        // e2: possibilities if previous number is 2 and current combined with previous number
        long e0 = 1, e1 = 0, e2 = 0, f0 = 0, M = 1e9 + 7;
        for (char c : s) {
            if (c == '*') {
                f0 = 9 * e0 + 9 * e1 + 6 * e2;
                e1 = e0;
                e2 = e0;
            } else {
                f0 = (c > '0') * e0 + e1 + (c <= '6') * e2;
                e1 = (c == '1') * e0;
                e2 = (c == '2') * e0;
            }
            e0 = f0 % M;
        }
        return e0;
    }
};