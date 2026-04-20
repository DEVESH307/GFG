#User function Template for python3

class Solution:
    def maxSum(self, N, mat):
        # code here
        arr = []
        arr = [max(a, b) for a, b in zip(mat[0], mat[1])]
        n = len(arr)
        dp = [-1] * (n + 1)

        def dfs(i):
            if i < 0:
                return 0

            if dp[i] != -1:
                return dp[i]
                
            pick = arr[i] + dfs(i - 2)
            not_pick = dfs(i - 1)
            dp[i] = max(pick, not_pick)

            return dp[i]

        return dfs(n - 1)