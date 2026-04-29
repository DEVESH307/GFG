# from collections import defaultdict, deque

# class Solution:
#     def isCyclic(self, V, edges):
#         # Kahn’s algorithm
#         # build graph and indegree list
#         graph = defaultdict(list)
#         indegree = [0] * (V + 1)
#         for u, v in edges:
#             graph[u].append(v)
#             indegree[v] += 1

#         queue = deque([i for i in range(1, V + 1) if indegree[i] == 0])
#         order = []

#         while queue:
#             node = queue.popleft()
#             order.append(node)

#             for nei in graph[node]:
#                 indegree[nei] -= 1
#                 if indegree[nei] == 0:
#                     queue.append(nei)

#         return 0 if len(order) == V else 1


# from collections import defaultdict, deque

# class Solution:
#     def isCyclic(self, V, edges):
#         # Kahn’s algorithm
#         graph = defaultdict(list)
#         indegree = [0] * (V + 1)

#         for u, v in edges:
#             graph[u].append(v)
#             indegree[v] += 1

#         queue = deque(i for i in range(1, V + 1) if indegree[i] == 0)
#         count = 0

#         while queue:
#             node = queue.popleft()
#             count += 1

#             for nei in graph[node]:
#                 indegree[nei] -= 1
#                 if indegree[nei] == 0:
#                     queue.append(nei)

#         return 0 if count == V else 1
 

from collections import defaultdict
import sys
sys.setrecursionlimit(10**6)
class Solution:
    def isCyclic(self, V, edges):
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)

        visited = [False] * (V + 1)
        path = [False] * (V + 1)

        def dfs(node):
            visited[node] = True
            path[node] = True

            for nei in graph[node]:
                if not visited[nei]:
                    if dfs(nei):
                        return True
                elif path[nei]:  # cycle detected
                    return True

            path[node] = False  # backtrack
            return False

        for i in range(1, V + 1):
            if not visited[i]:
                if dfs(i):
                    return 1

        return 0