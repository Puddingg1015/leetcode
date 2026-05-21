class Solution:

    def lenPrefix(self, a:str, b:str)->int:
        count = 0;
        for i in range(min(len(a), len(b))):
            if (a[i] != b[i]): return count;
            count += 1;
        return count

    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        maxlen = 0;
        arr1.sort(reverse=True)
        arr2.sort(reverse=True)
        prefixes = set()
        for b in arr2:
            sb = str(b)
            for i in range(1, len(sb) + 1):
                prefixes.add(sb[0:i])
        for a in arr1:
            sa = str(a)
            if (len(sa) < maxlen): continue;
            for i in range(1, len(sa) + 1):
                if (sa[0:i] in prefixes):
                    maxlen = max(maxlen, len(sa[0:i]))
        return maxlen