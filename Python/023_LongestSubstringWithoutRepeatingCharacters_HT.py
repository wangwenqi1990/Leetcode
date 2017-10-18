class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        d, left, res=dict(), 0, 0
        for i in range(len(s)):
            if not (s[i] in d) or d[s[i]] < left:
                res = max(res, i-left+1)
            else:
                left = d[s[i]]+1 #left should be one step larger than d[s[i]] since d[s[i]] is not counted for length
            d[s[i]] = i
        return res
        