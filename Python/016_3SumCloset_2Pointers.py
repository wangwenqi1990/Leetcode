class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        if n<3:
            return 0;
        
        nums = sorted(nums)
        res = nums[0] + nums[1] + nums[2]
        
        i =0
        while i< n-2:
            l, r = i+1, n-1
            while (l<r):
                s = nums[i] + nums[l] + nums[r]
                if(abs(s-target) < abs(res-target)):
                    res =s
                
                if (s < target):
                    l+=1
                elif (s>target):
                    r-=1
                else:
                    return res
            curNum = nums[i]
            while i<n-2 and nums[i]==curNum:
                i+=1
        return res