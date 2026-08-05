class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        return (max(nums) - 1) * (max(nums.remove(max(nums)) or nums) - 1)