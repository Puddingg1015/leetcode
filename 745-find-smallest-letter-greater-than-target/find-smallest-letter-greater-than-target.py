class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        for char in letters:
            if (ord(target) < ord(char)):
                return char;
        return letters[0];