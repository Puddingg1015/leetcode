class Solution:
    def minimumPushes(self, word: str) -> int:
        ## sighs
        # pushes = dict()
        # for i in range(25): pushes[chr(ord('a') + i)] = (i % 3) + 1
        # pushes['z'] = 4
        # return sum([pushes[char] for char in word])
        l = len(word)
        return min(l, 8) + 2*min(max(l-8, 0), 8) + 3*min(max(l-16, 0), 8) + 4*min(max(l-24, 0), 8)