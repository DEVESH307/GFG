#User function Template for python3

class Solution:
    def findPermutation(self, s):
        # Code here
        n = len(s)
        s = list(s)
        result = []

        def dfs(index):
            if index == n:
                result.append(''.join(s[:]))
                return
            used = set()
            for i in range(index, n):
                if s[i] in used:
                    continue
                used.add(s[i])

                s[index], s[i] = s[i], s[index]
                dfs(index + 1)
                s[i], s[index] = s[index], s[i]

        dfs(0)
        return result                
        
