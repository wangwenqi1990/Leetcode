#include "package_wwq.cpp"

/*
    Computational Complexity:   O(sp)
    Space Complexity:           O(sp)
*/
class Solution {
public:
    bool isMatch(string s, string p) {
    	int ls = s.length();
    	int lp = p.length();
    	// dp[i][j] means s[0]-> s[i-1] mathese p[0]-> p[j-1]
    	vector< vector<bool> > dp(ls+1, vector<bool>(lp+1, false) );
    	dp[0][0] = true;
    	for(int j=2; j< lp+1;j++){
    		if(p[j-1] =='*')
    			dp[0][j] = dp[0][j-2];
    	}


    	for(int i=1; i<ls+1; i++){
    		for(int j=1; j<lp+1;j++){
    			if(p[j-1] != '*')
    				dp[i][j] = dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
    			else
    				// char and '*' => 0 char
    				// char and '*' => 1 or more chars
                    // (1) s[0]->s[i-2] mathes p[0]->p[j-1] 
                    // (2) s[i-1] matches p[j-1](which has to be the same as p[j-1]) 
    				dp[i][j] = dp[i][j-2] || 	(dp[i-1][j] && (s[i-1]==p[j-2] || p[j-2]=='.'));
    		}
    	}

	   	return dp[ls][lp];
    }
};

int main(){
	string s = "aaa";
	string p = "ab*a*c*a";
    cout << Solution().isMatch(s, p) << endl;
}