class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        return [i for i in range(min(nums), max(nums) + 1) if not i in nums]