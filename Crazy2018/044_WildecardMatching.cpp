#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // space O(ps), which can be reduced to O(p), computation O(ps)
        int ls = s.size(), lp = p.size();
        // initialize the table
        bool dp[ls+1][lp+1];
        dp[0][0]=true;
        for(int j=1;j<lp+1;j++){
            if(p[j-1]=='*')
                dp[0][j]=dp[0][j-1];
            else
                dp[0][j]=false;
        }
        for(int i=1; i<ls+1;i++)
            dp[i][0]= false;
        
        // dp updating
        for(int j=1;j<lp+1; j++){
            for(int i=1;i<ls+1;i++){
                if(p[j-1]=='?' || p[j-1]==s[i-1])
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j]=dp[i-1][j-1]||dp[i-1][j]||dp[i][j-1];  // the core component
                else
                    dp[i][j]=false;
            }
        }
        return dp[ls][lp];
    }
};

int main(){
    string s = "a";
    string p = "a*";
    cout << Solution().isMatch(s, p) << endl;

}