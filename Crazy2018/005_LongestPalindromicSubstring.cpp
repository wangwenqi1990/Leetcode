class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0) return s;
        
        int start =0, maxlen=0;
        int k, len, j;
        for(int i=0; i<n; i++){
            // odd
            k=1, len=1;
            while(i-k>=0 && i+k <n && s[i-k]==s[i+k]){
                len+=2;
                k++;
            }
            if(len>maxlen){
                start  = i;
                maxlen = len;
            }
            
            // even
            j=i+1;
            k = 0,len =0;
            while(i-k>=0 && j+k<n && s[i-k]==s[j+k]){
                len += 2;
                k++;
            }
            if(len>maxlen){
                start  = i;
                maxlen = len;
            }    
        }
        return maxlen%2==0? s.substr(start-maxlen/2+1, maxlen):s.substr(start-(maxlen-1)/2,maxlen);
    }
};

// DP
class Solution {
public:
    string longestPalindrome(string s) {
        // dp[j][i] represents the substring, j,j+1,..., i, is a palindrome
        int n = s.size();
        int dp[n][n]={0};
        int left=0, right=0, len=0;
        
        for(int i=0; i< n; i++){
            for(int j=0; j< i; j++){
                dp[j][i]= (s[j]==s[i] && ((i-j<2) || dp[j+1][i-1]));
                if(dp[j][i] && len<i-j+1){
                    len = i-j+1;
                    left=j;
                    right=i;
                }
            }
            dp[i][i]=1;
        }
        return s.substr(left, right-left +1);
    }
};