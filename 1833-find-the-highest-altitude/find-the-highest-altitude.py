class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        h = 0;
        maxh = 0;
        for dh in gain: 
            h += dh
            if h > maxh:
                maxh = h
        return maxh