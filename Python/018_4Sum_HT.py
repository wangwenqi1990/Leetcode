class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        n,res, d= len(nums), set(),{}
        nums.sort()
        
         build the harshtable for all pairs
        for i in range(n-1):
            for j in range(i+1, n):
                tp = nums[i] + nums[j]
                if tp in d:
                    d[tp].append((i,j))
                else:
                    d[tp]=[(i,j)]
        
        # for each pair, check the hash table and update if index are larger than j
        for i in range(n-3):
            for j in range(i+1, n-2):
                tp = nums[i] + nums[j]
                if target-tp in d:
                    for pair in d[target-tp]:
                        if pair[0]>j:
                            res.add((nums[i], nums[j],nums[pair[0]], nums[pair[1]] ))
        
        return [list(i) for i in res ]