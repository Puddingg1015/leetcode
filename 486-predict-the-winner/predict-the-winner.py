class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        if len(nums) == 3:
            return nums[1] < nums[0] + nums[2]
        p1, p2 = self.getMaxScores(nums, 0, 0, 1)
        return p1 >= p2

    def getMaxScores(self, nums, p1_score, p2_score, turn=1) -> tuple[int]:
        if len(nums) == 0:
            return (p1_score, p2_score)
        if turn == 1:
            if (len(nums) == 1): 
                return (p1_score + nums[0], p2_score)
            p1_score += nums[0]
            final_l = self.getMaxScores(nums[1:], p1_score, p2_score, turn=2)
            p1_score += nums[-1] - nums[0]
            final_r = self.getMaxScores(nums[:-1], p1_score, p2_score, turn=2)
            if (final_l[0] > final_r[0] or (final_l[0] == final_r[0] and final_l[1] < final_r[1])):
                return final_l
            else:
                return final_r
        if turn == 2:
            if (len(nums) <= 1): 
                return (p1_score, p2_score + nums[0])
            p2_score += nums[0]
            final_l = self.getMaxScores(nums[1:], p1_score, p2_score, turn=1)
            p2_score += nums[-1] - nums[0]
            final_r = self.getMaxScores(nums[:-1], p1_score, p2_score, turn=1)
            if (final_l[1] > final_r[1] or (final_l[1] == final_r[1] and final_l[0] < final_r[0])):
                return final_l
            else:
                return final_r