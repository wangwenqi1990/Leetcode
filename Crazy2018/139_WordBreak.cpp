class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // computation: O(n^2)  Space: O(n)
        unordered_set<string> h;
        for(auto w: wordDict){
            h.insert(w);
        }
        
        int n = s.size();
        bool dp[n+1]={true};
        for(int i=1; i<n+1; i++){
            for(int j=0; j<i; j++){
                if(dp[j]==true && h.count(s.substr(j, i-j))){
                    dp[i]=true; break;
                }
            }
        }
        return dp[n];
    }
};
