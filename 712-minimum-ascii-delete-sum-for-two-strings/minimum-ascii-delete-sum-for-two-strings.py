class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        min_val = [[0 for col in range(len(s2)+1)] for row in range(len(s1)+1)]; # [i][j] is min COMMON sum ending at s1[:i+1] and s2[:j+1]
        # if (s1[0] == s2[0]): min_val[0][0] = 0;
        # else: min_val[0][0] = ord(s1[0]) + ord(s2[0]);
        for i in range(1, len(s1)+1):
            min_val[i][0] = min_val[i-1][0] + ord(s1[i-1]);
        for j in range(1, len(s2)+1):
            min_val[0][j] = min_val[0][j-1] + ord(s2[j-1]);
        for i in range(1, len(s1)+1):
            for j in range(1, len(s2)+1):
                if (s1[i-1] == s2[j-1]):
                    min_val[i][j] = min_val[i-1][j-1];
                else:
                    min_val[i][j] = min(min_val[i-1][j] + ord(s1[i-1]), min_val[i][j-1] + ord(s2[j-1]));
        # print(" ", end = "\t");
        # [print(s2[coli], end = "\t") for coli in range(len(s2))];
        # print();
        # [print(min_val[rowi]) for rowi in range(len(min_val))];
        return min_val[len(s1)][len(s2)];
            