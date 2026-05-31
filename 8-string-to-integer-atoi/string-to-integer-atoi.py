class Solution:
    def myAtoi(self, s: str) -> int:
        n = 0
        s = s.strip()
        if len(s) == 0:
            return n;
        i = 0
        neg = False;
        if s[0] in ('+', '-'):
            neg = s[0] == '-'
            i += 1;
        while i < len(s):
            if s[i].isdigit():
                n = n*10 + int(s[i])
            else:
                break;
            i += 1;
        n = (-1)**neg * n;
        if n < -2**31: n = -2**31
        if n > 2**31 - 1: n = 2**31 - 1
        return n

            