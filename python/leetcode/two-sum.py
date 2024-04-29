from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = [0,0]
        flag = False
        for p1 in range(len(nums)):
            if flag:
                break
            for p2 in range(p1+1, len(nums)):
                if nums[p1] + nums[p2] == target:
                    res = [p1, p2]
                    flag = True
                    break
        return res

print(Solution().twoSum([-3,4,3,90], 0))
