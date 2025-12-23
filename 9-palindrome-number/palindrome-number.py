class Solution:
    def isPalindrome(self, x: int) -> bool:
        string = str(x);
        for i in range(len(string)):
            if (string[i] != string[len(string) - i - 1]):
                return False;
        return True;