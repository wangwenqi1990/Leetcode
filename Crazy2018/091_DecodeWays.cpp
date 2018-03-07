class Solution {
public:
    int numDecodings(string s) {
        int res = 0, n = s.size();
        vector<int> dp(n+1, 1);
        if(n==0) return res;
        if(s[0]=='0') return res;
        for(int i=1; i< n; i++){
            if(s[i]=='0'){
                if(s[i-1]!='1' && s[i-1]!='2')  return 0;
                else dp[i+1]=dp[i-1];
            }
            else if(s[i]>='1' && s[i]<='6'){
                dp[i+1]=dp[i];
                if(s[i-1]=='1' || s[i-1]=='2')  dp[i+1]+=dp[i-1];
            }
            else{
                dp[i+1]=dp[i];
                if(s[i-1]=='1') dp[i+1]+=dp[i-1];
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==0) return 0;
        vector<int>dp(n+1, 0);dp[0]=1;
        for(int i=0; i<n;++i){
            int tp = s[i]-'0';
            if(tp==0){
                if(i>0 && (s[i-1]=='1'||s[i-1]=='2'))   dp[i+1]+=dp[i-1];
                else    return 0;
            }
            else if(tp>=1 && tp<=6){
                dp[i+1]+=dp[i];
                if(i>0 && (s[i-1]=='1'||s[i-1]=='2'))   dp[i+1]+=dp[i-1];
            }
            else{
                dp[i+1]+=dp[i];
                if(i>0 && s[i-1]=='1')   dp[i+1]+=dp[i-1];
            }
        }
        return dp[n];
    }
};
