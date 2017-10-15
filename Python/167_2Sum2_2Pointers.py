class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        l, r = 0, len(numbers)-1
    	res =[]
        while(l<r):
        	s = numbers[l]+numbers[r]
        	if s < target:
        		l+=1
        	elif s > target:
        		r-=1
        	else:
        		res.append(l+1)
        		res.append(r+1)
        		return res
        return res

