class Solution:
    def processStr(self, s: str) -> str:
        result = ""
        for char in s:
            if char.islower():
                result += char
            if char == '*' and len(result):
                result = result[0:-1]
            if char == '#':
                result += result
            if char == '%':
                result = result[::-1]
        return result