class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        # silly
        return max((hs:=[sum(gain[0:i+1]) for i in range(len(gain))]).append(0) or hs)
