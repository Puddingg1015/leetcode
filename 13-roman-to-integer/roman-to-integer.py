class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        numerals = {"I" : 1, "V" : 5, "X" : 10, "L" : 50, "C" : 100, "D" : 500, "M" : 1000};
        num = 0;
        s = s[::-1];
        prev_val = 0;
        for char in s:
            if (numerals[char] < prev_val):
                num -= numerals[char];
            else:
                num += numerals[char];
                prev_val = numerals[char];
        return num;