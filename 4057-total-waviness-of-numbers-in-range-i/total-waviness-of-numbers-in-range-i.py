class Solution:
    # Goober questions goober solutions
    def totalWaviness(self, num1: int, num2: int) -> int:
        def waveiness(n):
            if n < 100: return 0
            return (((a := n%10) + (b := (n//10)%10) + (c := (n//100)%10)) and ((a < b and b > c) or (a > b and b < c))) + waveiness(n//10)
        return sum(list(map(waveiness, range(num1, num2+1))))