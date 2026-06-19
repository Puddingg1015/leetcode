class Solution:
    def isIncreasing(self, nums):
        for i in range(len(nums) - 1):
            if nums[i] > nums[i+1]:
                return False;
        return True;

    def minimumPairRemoval(self, nums: List[int]) -> int:
        ops = 0;
        while (not self.isIncreasing(nums)):
            min_sum = nums[0] + nums[1];
            min_i = 0;
            for i in range(len(nums) - 1):
                pair_sum = nums[i] + nums[i+1];
                if pair_sum < min_sum:
                    min_i = i;
                    min_sum = pair_sum;
            nums.pop(min_i + 1);
            nums[min_i] = min_sum;
            ops += 1;
        return ops;

            