class Solution:

    def check(self, nums: List[int]) -> bool:
        s = len(nums);
        for offset in range(s):
            is_sorted = True;
            for i in range(s - 1):
                reali = (i + offset) % s;
                if (reali == s - 1):
                    reali = -1;
                if (nums[reali] > nums[reali + 1]):
                    is_sorted = False;
            if (is_sorted):
                return True;
        return False;