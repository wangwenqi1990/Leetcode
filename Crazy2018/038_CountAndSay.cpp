class Solution {
public:
    string countAndSay(int n) {
        if(n<=0) return "";
        string res = "1";
        while(--n){
            string cur;
            // for each n generate its read results cur
            for(int i=0; i<res.size();++i){
                int cnt = 1;
                while(i+1<res.size() && res[i]==res[i+1]){
                    ++i; ++cnt;
                }
                cur += to_string(cnt)+res[i];                
            }
            res = cur;
        }
        return res;
    }
};