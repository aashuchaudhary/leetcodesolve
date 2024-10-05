class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        rows, cols = len(grid), len(grid[0])

        # Marking Position and shell visited
        visited = set()

        islands = 0

        def bfs(r ,c):
            q = collections.deque()
            # Marking Position
            visited.add((r,c))
            # Adding in queue
            q.append((r, c))

            # q is nt empty means expanding island
            while q:
                row, col = q.popleft()
                directions = [[1,0],[-1,0],[0,1],[0,-1]]
# For each of the directions
                for dr, dc in directions:
                    r, c = row + dr, col + dc
                    # Checking the position and the position is land
                    if 0 <= r < rows and 0 <= c < cols and grid[r][c] == "1" and (r, c) not in visited: 

                        # it its true then add into queue
                        q.append((r, c))
                        # we have to mark visit so we dont visit twice
                        visited.add((r, c))
# Visit every single position in grid
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1" and (r, c) not in visited:
                    # Traverse and marked as visit (use bfs)
                    islands += 1
                    bfs(r, c)

        return islands

