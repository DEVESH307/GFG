class Solution:
    def ratInMaze(self, maze):
        n = len(maze)
        res = []
        
        if maze[0][0] == 0 or maze[n-1][n-1] == 0:
            return res
        
        visited = [[False]*n for _ in range(n)]
        visited[0][0] = True  # mark start
        
        directions = [
            ('D', 1, 0),
            ('L', 0, -1),
            ('R', 0, 1),
            ('U', -1, 0)
        ]
        
        def dfs(x, y, path):
            if x == n-1 and y == n-1:
                res.append(path)
                return
            
            for move, dx, dy in directions:
                nx, ny = x + dx, y + dy
                
                if (0 <= nx < n and 0 <= ny < n and
                    maze[nx][ny] == 1 and not visited[nx][ny]):
                    
                    visited[nx][ny] = True
                    dfs(nx, ny, path + move)
                    visited[nx][ny] = False  # backtrack
        
        dfs(0, 0, "")
        return res