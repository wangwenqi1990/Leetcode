class Solution(object):
    def isMatch(self, s, p):
        res = [[False for j in xrange(len(p)+1)] for i in xrange(len(s) + 1)]
        res[0][0] = True
        for j in xrange(2, len(p)+1):
            if p[j-1] == '*':
                res[0][j] = res[0][j-2]

        for i in xrange(1, len(s)+1):
            for j in xrange(1, len(p)+1):
                if p[j-1] != '*':
                    res[i][j] = res[i-1][j-1] and (s[i-1]==p[j-1] or p[j-1] == '.')
                else:
                    res[i][j] = res[i][j-2] \
                                or ( res[i-1][j] and (s[i-1] == p[j-2] or p[j-2] =='.') )

        return res[len(s)][len(p)]

s = 'aa'
p = 'a*'
print Solution().isMatch(s, p)