class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stk = [];
        for i in s:
            if i=='(' or i=='{' or i=='[':
                stk.append(i)
            else:
                if not stk:
                    return False
                elif (i==']' and stk[-1]=='[') or (i==')' and stk[-1]=='(') or (i=='}' and stk[-1]=='{'):
                    stk=stk[:-1]
                else:
                    return False
        
        return not stk