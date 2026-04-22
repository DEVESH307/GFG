#User function Template for python3

class Solution:
	def LongestRepeatingSubsequence(self, s):
		# Code here
		t = s[:]
        ls = lt = len(s)
        dp = [[None] * (lt + 1) for _ in range(ls + 1)]

        def dfs(i, j):
            if i == 0 or j == 0:
                return 0

            if dp[i][j] is not None:
                return dp[i][j]

            if s[i-1] == t[j-1] and i != j:
                dp[i][j] = 1 + dfs(i-1, j-1)
            else:
                dp[i][j] = max(dfs(i-1, j), dfs(i, j-1))

            return dp[i][j]

        return dfs(ls, lt)