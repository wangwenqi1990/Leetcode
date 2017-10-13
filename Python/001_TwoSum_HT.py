class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        tp = dict()
        for i in range(len(nums)):
            if target-nums[i] in tp:
                return [tp[target-nums[i]], i]
            else:
                tp[nums[i]]=i
        return []