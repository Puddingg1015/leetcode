class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        # chat how are people doing this question in O(N) time :wilted_rose:
        for i in range(max(bool(asteroids.sort()),len(asteroids))): mass += (asteroids[i] if mass >= asteroids[i] else float("-inf"))
        return (mass > 0)