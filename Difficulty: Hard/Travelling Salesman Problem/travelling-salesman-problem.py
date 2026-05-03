class Solution:
    def tsp(self, cost):
        n = len(cost)

        # Edge case: only one city → no travel needed
        if n == 1:
            return 0

        INF = float('inf')

        # dp[mask][u] = minimum cost to reach city u
        # after visiting all cities in 'mask'
        dp = [[INF] * n for _ in range(1 << n)]

        # Start from city 0
        # mask = 000...001 → only city 0 is visited
        dp[1][0] = 0

        # Iterate over all subsets of cities (mask)
        for mask in range(1 << n):

            # Try every possible current city u
            for u in range(n):

                # Skip if city u is NOT included in mask
                if not (mask & (1 << u)):
                    continue

                # Try going to next city v
                for v in range(n):

                    # Skip if city v is already visited
                    if mask & (1 << v):
                        continue

                    # New mask after visiting city v
                    new_mask = mask | (1 << v)

                    # Update DP:
                    # current cost + cost from u → v
                    dp[new_mask][v] = min(
                        dp[new_mask][v],
                        dp[mask][u] + cost[u][v]
                    )

        # All cities visited mask (111...111)
        final_mask = (1 << n) - 1

        ans = INF

        # After visiting all cities, return to city 0
        for u in range(n):
            ans = min(ans, dp[final_mask][u] + cost[u][0])

        return ans