/*
Computation: O(n)
Space: O(1)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //m is the mapping from char to location (i+1); if 0, meaning never occur
        int m[256]={0}, res=0, left= 0;
        for(int i=0; i< s.size(); i++){
            if(m[s[i]] == 0 || m[s[i]] < left){
                res = max(res, i-left+1);
            }
            else{
                left = m[s[i]];
            }
            m[s[i]]=i+1;
        }
        return res;
    }
};