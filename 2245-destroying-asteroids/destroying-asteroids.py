class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        # one line solution! (amazing i know) Somehow beats 85% mem :P
        return (cm:=mass) and (min([(cm := cm + (asteroids[i] if cm >= asteroids[i] else float("-inf"))) for i in range(max(bool(asteroids.sort()),len(asteroids)))]) > 0)