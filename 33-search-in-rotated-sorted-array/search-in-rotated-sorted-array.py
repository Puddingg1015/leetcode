class Solution:

    nums = None;
    
    # inclusive
    def findStart(self, l, r)->int:
        if (l > r): return -1;
        m = (l+r)//2;
        if (self.nums[m - 1] > self.nums[m]):
            return m;
        return max(self.findStart(l, m - 1), self.findStart(m + 1, r))

    def search(self, nums: List[int], target: int) -> int:
        if (nums[0] == target): return 0;
        self.nums = nums;
        s = len(nums);
        offset = self.findStart(0, s - 1);
        l = 0;
        r = s - 1;
        while (l <= r):
            m = (l + r)//2
            num = nums[(m + offset) % s];
            if (num == target):
                return (m + offset) % s
            elif (num < target):
                l = m + 1
            else:
                r = m - 1 
        return -1;
            


