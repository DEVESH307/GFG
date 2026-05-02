class Solution:
    def floydWarshall(self, dist):
        n = len(dist)
        INF = int(1e8)

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dist[i][k] != INF and dist[k][j] != INF:
                        dist[i][j] = min(dist[i][j],
                                         dist[i][k] + dist[k][j])