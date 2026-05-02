# class Solution:
#     def bellmanFord(self, V, edges, src):
#         INF = 10**8
#         dist = [INF] * V
#         dist[src] = 0

#         # Step 1: Relax edges V-1 times
#         for _ in range(V - 1):
#             for u, v, w in edges:
#                 if dist[u] != INF and dist[u] + w < dist[v]:
#                     dist[v] = dist[u] + w

#         # Step 2: Detect negative cycle
#         for u, v, w in edges:
#             if dist[u] != INF and dist[u] + w < dist[v]:
#                 return [-1]

#         return dist


from collections import deque

class Solution:
    def bellmanFord(self, V, edges, src):
        INF = 10**8

        # build adjacency list
        graph = [[] for _ in range(V)]
        for u, v, w in edges:
            graph[u].append((v, w))

        dist = [INF] * V
        dist[src] = 0

        # queue for processing
        q = deque([src])
        in_queue = [False] * V
        in_queue[src] = True

        # to detect negative cycle
        count = [0] * V

        while q:
            node = q.popleft()
            in_queue[node] = False

            for nei, w in graph[node]:
                if dist[node] + w < dist[nei]:
                    dist[nei] = dist[node] + w

                    if not in_queue[nei]:
                        q.append(nei)
                        in_queue[nei] = True
                        count[nei] += 1

                        # 🔴 negative cycle detection
                        if count[nei] >= V:
                            return [-1]

        return dist