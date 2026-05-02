from collections import defaultdict

class Solution:
    def kosaraju(self, V, edges):
        graph = defaultdict(list)
        rev_graph = defaultdict(list)

        # build graph and reverse graph
        for u, v in edges:
            graph[u].append(v)
            rev_graph[v].append(u)

        visited = [False] * V
        stack = []

        # Step 1: DFS to fill stack
        def dfs1(node):
            visited[node] = True
            for nei in graph[node]:
                if not visited[nei]:
                    dfs1(nei)
            stack.append(node)

        for i in range(V):
            if not visited[i]:
                dfs1(i)

        # Step 2: DFS on reversed graph
        visited = [False] * V
        scc_count = 0

        def dfs2(node):
            visited[node] = True
            for nei in rev_graph[node]:
                if not visited[nei]:
                    dfs2(nei)

        # Step 3: process nodes in reverse finishing order
        while stack:
            node = stack.pop()
            if not visited[node]:
                dfs2(node)
                scc_count += 1

        return scc_count