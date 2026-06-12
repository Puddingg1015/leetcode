class Solution:

    MOD = 10**9 + 7
    adj_list = [list() for i in range(100001)]
    visited = set()

    def height(self, curr):
        self.visited.add(curr)
        if len(self.adj_list[curr]) == 0:
            return 0
        max_depth = 0
        for v in self.adj_list[curr]:
            if (v != curr and v not in self.visited):
                max_depth = max(self.height(v) + 1, max_depth)
        return max_depth

    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        # assume directed i guess
        # nvm
        self.adj_list = [list() for i in range(100001)]
        self.visited = set()
        for edge_pair in edges:
            u, v = edge_pair[0], edge_pair[1]
            self.adj_list[u].append(v)
            self.adj_list[v].append(u)
        height = self.height(1)
        return 2**(height - 1) % self.MOD
