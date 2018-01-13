class Solution {
public:
    int strStr(string haystack, string needle) {
        // computation: O(nk) space: O(1)
        if(needle.empty())  return 0;
        int h = haystack.size(), n=needle.size();
        if(n>h) return -1;
        for(int i=0; i<=h-n;i++){
            int j=0;
            for(; j<n; j++){
                if(haystack[i+j]!=needle[j])
                    break;
            }
            if(j==n)
                return i;
        }
        return -1;
    }
};