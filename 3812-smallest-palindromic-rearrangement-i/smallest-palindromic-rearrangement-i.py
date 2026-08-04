class Solution:
    def smallestPalindrome(self, s: str) -> str:
        l = len(s)
        mid = s[l//2] if l % 2 else ""
        part = "".join(sorted([c for c in s[:l//2]]))
        return part + mid + part[::-1]