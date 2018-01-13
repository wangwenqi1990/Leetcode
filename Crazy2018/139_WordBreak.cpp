class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //  j,...., i
        // sj,....,si
        // hash-table
        int n = s.size();
        
        // hash table
        unordered_set<string> h;
        for(int i=0; i<wordDict.size();i++)
            h.insert(wordDict[i]);
        
        // dp[i] means till the ith word in s,the word can be break or not;
        bool dp[n+1]={false};
        dp[0]= true;
        for(int i=1; i<n+1; i++){
            for(int j=0; j<i;j++){
                if(dp[j] && h.find(s.substr(j,i-j))!=h.end())
                    {dp[i]=true;break;}
            }
        }
        return dp[n];
    }  
};