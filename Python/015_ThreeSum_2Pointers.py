class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums, n, res, i= sorted(nums), len(nums),[],0
        while i< n-2:
        	l, r = i+1, n-1
        	target = -nums[i]
        	while l < r:
        		s = nums[l] + nums[r]
        		tp_l, tp_r = nums[l], nums[r]

        		if s < target:
        			while l<r and nums[l] == tp_l:
        				l+=1
        		elif s>target:
        			while l<r and nums[r] == tp_r:
        				r-=1
        		else:
        			res.append([nums[i], nums[l], nums[r]])

        			while l<r and nums[l] == tp_l:
        				l+=1
        			while l<r and nums[r] == tp_r:
        				r-=1

        	tp_i = nums[i]
        	while i<n-2 and nums[i] == tp_i:
        		i+=1

        return res
