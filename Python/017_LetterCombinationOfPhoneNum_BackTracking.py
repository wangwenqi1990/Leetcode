class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        d, res={},[];
        d['0'], d['1'],d['2'], d['3'],d['4'], d['5'],d['6'], d['7'],d['8'], d['9'] ="","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        
        for i in digits:
            if not res:
                for tp in d[i]:
                    res.append(tp);
            else:
                tmp = []
                for tp1 in res:
                    for tp2 in d[i]:
                        tmp.append(tp1+tp2)
                res = tmp
        return res
                