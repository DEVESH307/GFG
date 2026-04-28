# from collections import defaultdict

# class Solution:
#     def isCycle(self, V, edges):
#         graph = defaultdict(list)

#         for u, v in edges:
#             graph[u].append(v)
#             graph[v].append(u)

#         visited = [False] * V

#         def dfs(node, parent):
#             visited[node] = True

#             for nei in graph[node]:
#                 if not visited[nei]:
#                     if dfs(nei, node):
#                         return True
#                 elif nei != parent:
#                     return True

#             return False

#         for i in range(V):
#             if not visited[i]:
#                 if dfs(i, -1):
#                     return 1

#         return 0