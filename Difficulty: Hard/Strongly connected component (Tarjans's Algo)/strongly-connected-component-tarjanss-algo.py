class Solution:
    def tarjans(self, V, adj):
        self.timer = 0
        disc = [-1] * V
        low = [-1] * V
        stack = []
        in_stack = [False] * V
        result = []

        def dfs(node):
            disc[node] = low[node] = self.timer
            self.timer += 1

            stack.append(node)
            in_stack[node] = True

            for nei in adj[node]:
                if disc[nei] == -1:
                    dfs(nei)
                    low[node] = min(low[node], low[nei])
                elif in_stack[nei]:
                    low[node] = min(low[node], disc[nei])

            # root of SCC
            if disc[node] == low[node]:
                scc = []
                while True:
                    cur = stack.pop()
                    in_stack[cur] = False
                    scc.append(cur)
                    if cur == node:
                        break
                scc.sort()
                result.append(scc)

        for i in range(V):
            if disc[i] == -1:
                dfs(i)

        # sort final result lexicographically
        result.sort()
        return result