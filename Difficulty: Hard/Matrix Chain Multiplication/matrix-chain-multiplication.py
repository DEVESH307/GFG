# import sys
# sys.setrecursionlimit(10**6)
# class Solution:
#     def matrixMultiplication(self, arr):

#         def dfs(s, e):
#             if s ==  e:
#                 return 0

#             ans = float('inf')
#             for i in range(s, e):
#                 left = dfs(s, i)
#                 right = dfs(i+1, e)
#                 cost = arr[s-1] * arr[i] * arr[e]

#                 total = left + right + cost
#                 ans = min(ans, total)

#             return ans

#         return dfs(1, len(arr) - 1)


# import sys
# sys.setrecursionlimit(10**6)
# class Solution:
#     def matrixMultiplication(self, arr):
#         n = len(arr)

#         # dp[s][e] stores answer for dfs(s, e)
#         dp = [[-1] * n for _ in range(n)]

#         def dfs(s, e):
#             if s == e:
#                 return 0

#             if dp[s][e] != -1:
#                 return dp[s][e]

#             ans = float('inf')

#             for i in range(s, e):
#                 left = dfs(s, i)
#                 right = dfs(i + 1, e)

#                 cost = arr[s - 1] * arr[i] * arr[e]
#                 total = left + right + cost

#                 ans = min(ans, total)

#             dp[s][e] = ans
#             return ans

#         return dfs(1, n - 1)


class Solution:
    def matrixMultiplication(self, arr):
        n = len(arr)

        # dp[s][e] = min cost to multiply matrices s → e
        dp = [[0] * n for _ in range(n)]

        # length = number of matrices in chain
        for length in range(2, n):   # minimum chain length = 2
            for s in range(1, n - length + 1):
                e = s + length - 1

                dp[s][e] = float('inf')

                for i in range(s, e):
                    cost = (
                        dp[s][i]
                        + dp[i + 1][e]
                        + arr[s - 1] * arr[i] * arr[e]
                    )
                    dp[s][e] = min(dp[s][e], cost)

        return dp[1][n - 1]