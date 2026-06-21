class Solution:
    # silly questions get silly solutions
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        return costs.sort() or sum([cost<=coins and (coins:=coins-cost)>=0 for cost in costs])