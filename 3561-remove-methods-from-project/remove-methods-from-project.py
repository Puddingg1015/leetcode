class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        adj_list = [list() for i in range(n)]
        for pair in invocations:
            adj_list[pair[0]].append(pair[1])
        suses = set()
        q = [k]
        while len(q) > 0:
            curr = q.pop(0)
            suses.add(curr)
            for u in adj_list[curr]:
                if u not in suses:
                    q.append(u)
        out = []
        for u in range(n):
            if u not in suses: 
                for v in adj_list[u]:
                    if v in suses:
                        return list(range(n))
                out.append(u)
        return out