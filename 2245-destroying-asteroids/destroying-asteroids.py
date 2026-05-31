class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        # chat how are people doing this question in O(N) time :wilted_rose:
        asteroids.sort();
        for i in range(len(asteroids)): 
            if (mass >= asteroids[i]): mass += asteroids[i];
            else: return False;
        return True;