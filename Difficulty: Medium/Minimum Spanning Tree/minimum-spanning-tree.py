import heapq
from collections import defaultdict

class Solution:
    def spanningTree(self, V, edges):
        # code here
        graph = defaultdict(list)
        
        # builf adjacency list
        for u, v, w in edges:
            graph[u].append((v, w))
            graph[v].append((u, w))
        
        visited = [False] * V
        min_heap = [(0, 0)] # (weight, node)
        mst_weight = 0
        
        while min_heap:
            w, node = heapq.heappop(min_heap)
        
            if visited[node]:
                continue
        
            visited[node] = True
            mst_weight += w
        
            for nei, wt in graph[node]:
                if not visited[nei]:
                    heapq.heappush(min_heap, (wt, nei))
        
        return mst_weight