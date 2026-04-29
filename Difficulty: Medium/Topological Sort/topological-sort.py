from collections import defaultdict, deque

class Solution:
    def topoSort(self, V, edges):
        # Code here
        # build graph
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)

        # build indegree list
        indegree = [0] * (V)
        for u, v in edges:
            indegree[v] += 1

        queue = deque([i for i in range(V) if indegree[i] == 0])
        order = []

        while queue:
            node = queue.popleft()
            order.append(node)

            for nei in graph[node]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    queue.append(nei)

        return order