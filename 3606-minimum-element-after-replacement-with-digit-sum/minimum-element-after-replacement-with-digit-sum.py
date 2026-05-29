# funny
class Solution: 
    def minElement(self, nums: List[int]) -> int: return min([max(bool(nums.__setitem__(i, sum(map(int, str(nums[i]))))), nums[i]) for i in range(len(nums))])