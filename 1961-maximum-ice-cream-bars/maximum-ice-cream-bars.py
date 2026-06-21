class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        # silly questions get silly solutions
        return costs.sort() or sum([True if cost<=coins and (coins:=coins-cost)>=0 else False for cost in costs])