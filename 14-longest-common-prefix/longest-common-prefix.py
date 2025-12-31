class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = "";
        for index in range(min([len(string) for string in strs])):
            char = strs[-1][index];
            print(char);
            isValid = True;
            for i in range(len(strs)-1):
                if (strs[i][index] != char):
                    isValid = False;
            if isValid:
                prefix += char;
            else:
                break;
        return prefix;