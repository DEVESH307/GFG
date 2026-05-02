#User function Template for python3
from typing import List

class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, u, v):
        pu, pv = self.find(u), self.find(v)

        if pu == pv:
            return False

        if self.rank[pu] < self.rank[pv]:
            self.parent[pu] = pv
        elif self.rank[pv] < self.rank[pu]:
            self.parent[pv] = pu
        else:
            self.parent[pv] = pu
            self.rank[pu] += 1

        return True


class Solution:
    def kruskalsMST(self, V: int, edges: List[List[int]]) -> int:
        # code here
        edges.sort(key=lambda x: x[2]) # sort weight by edges

        dsu = DSU(V)
        mst_weight = 0

        for u, v, w in edges:
            if dsu.union(u, v): # no cycle
                mst_weight += w

        return mst_weight
