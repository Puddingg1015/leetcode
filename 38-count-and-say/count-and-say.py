def rle(n):
    n += " "
    count = 0
    out = ""
    for i in range(len(n) - 1):
        count += 1
        cur = n[i]
        nxt = n[i + 1]
        if cur != nxt:
            out += str(count) + cur
            count = 0
    # print(out)
    return out


class Solution:

    def countAndSay(self, n: int) -> str:
        string = "1"
        for i in range(1, n): string = rle(string)
        return string