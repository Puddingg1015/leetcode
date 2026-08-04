class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        l = len(nums[0])
        nums = [int(n, 2) for n in nums]
        i = 0
        while i in nums: i += 1
        return f"{bin(i).split("0b")[1].zfill(l)}"