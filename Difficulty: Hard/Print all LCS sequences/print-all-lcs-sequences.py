from functools import lru_cache

class Solution:
    def allLCS(self, s1, s2):
        l1, l2 = len(s1), len(s2)
        
        # build DP table (lengths)
        dp = [[0]*(l2+1) for _ in range(l1+1)]
        
        for i in range(1, l1+1):
            for j in range(1, l2+1):
                if s1[i-1] == s2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        
        @lru_cache(None)
        def dfs(i, j):
            if i == 0 or j == 0:
                return {""}
            
            if s1[i-1] == s2[j-1]:
                return {x + s1[i-1] for x in dfs(i-1, j-1)}
            
            res = set()
            
            if dp[i-1][j] >= dp[i][j-1]:
                res |= dfs(i-1, j)
            
            if dp[i][j-1] >= dp[i-1][j]:
                res |= dfs(i, j-1)
            
            return res
        
        return sorted(dfs(l1, l2))