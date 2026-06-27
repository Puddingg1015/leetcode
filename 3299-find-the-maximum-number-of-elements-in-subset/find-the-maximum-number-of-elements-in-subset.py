from bisect import *

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        # brute force go brrr
        maxlen = ((nums.count(1) - 1)//2) * 2 + 1
        maxval = max(nums)
        if maxval == 1:
            return maxlen
        nums.sort()
        nums.append(0)
        visited = set()
        for start in nums:
            if start in visited or start == 1:
                continue
            visited.add(start)
            length = 0
            curr = start
            # print(start, end=": ")
            while (True):
                # print((curr, length), end="->")
                # py builtin upper/lowerbound when
                lp = bisect_left(nums, curr)
                rp = bisect_right(nums, curr)
                count = 0
                if lp < len(nums) and nums[lp] == curr:
                    count = rp - lp
                if count >= 2:
                    length += 2
                if count == 1:
                    length += 1
                    break
                if count < 1:
                    length -= 1
                    break
                curr *= curr
            if length > maxlen:
                maxlen = length
            # print("; ", length)
        return maxlen
