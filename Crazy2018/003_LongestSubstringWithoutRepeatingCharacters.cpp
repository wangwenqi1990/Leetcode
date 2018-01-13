class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, l = s.size(), res=0;
        unordered_map<char, int> m;
        for(int i=0; i< l; i++){
            // substring index: left, left+1,..., i-1
            if(m.find(s[i]) != m.end() && m[s[i]] >= left){
                res = max(res, i-left);
                left = m[s[i]]+1;
                m[s[i]]=i;
            }
            else{
                m[s[i]] = i;
            }
        }
        return max(res, l-left);
    }
};