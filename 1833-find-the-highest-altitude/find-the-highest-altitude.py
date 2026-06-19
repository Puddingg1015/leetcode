class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        h = 0;
        maxh = 0;
        for dh in gain: maxh = max(maxh, h:=h+dh)
        return maxh