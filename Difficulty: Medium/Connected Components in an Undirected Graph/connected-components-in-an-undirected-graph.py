from collections import defaultdict

class Solution:
    def getComponents(self, V, edges):
        # code here
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = set()
        result = []

        def dfs(node, component):
            if node in visited:
                return

            visited.add(node)
            component.append(node)

            for nei in graph[node]:
                if nei not in visited:
                    dfs(nei, component)


        for node in range(V):
            if node not in visited:
                component = []
                # connected_components += 1
                dfs(node, component)
                result.append(component)

        return result