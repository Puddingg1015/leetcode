class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        hr_a = (hour + minutes/60)/12 * 360
        min_a = minutes/60 * 360
        return min(abs(hr_a - min_a), 360 - abs(hr_a - min_a))

