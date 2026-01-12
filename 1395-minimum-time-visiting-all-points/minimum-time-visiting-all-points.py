class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        pos = points[0];
        time = 0;
        for point in points:
            d = [abs(point[0] - pos[0]), abs(point[1] - pos[1])];
            time += min(d) + max((d[0] - min(d), d[1] - min(d)));
            pos = point;
        return time;
            
            