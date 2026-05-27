class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        upperlower = [False for _ in range(26 * 2)]; 
        for char in word: upperlower[ord(char) - (ord('a') if char.islower() else ord('A') - 26)] = True;
        #print(list(enumerate(upperlower)), len(upperlower))
        return sum([(upperlower[i] and upperlower[i + 26]) for i in range(26)]);