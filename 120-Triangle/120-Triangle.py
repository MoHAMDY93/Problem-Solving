# Last updated: 6/10/2026, 7:26:41 PM
class Solution(object):
    def minimumTotal(self, triangle):
        n = len(triangle)
    
        # Each node will be identified as (r, c)
        graph = defaultdict(list)
        
        # Build DAG edges
        for r in range(n - 1):
            for c in range(len(triangle[r])):
                u = (r, c)
                v1 = (r + 1, c)
                v2 = (r + 1, c + 1)
                graph[u].append((v1, triangle[r + 1][c]))
                graph[u].append((v2, triangle[r + 1][c + 1]))
        
        # Distance dictionary, start from top
        dist = {(0, 0): triangle[0][0]}
        
        # Topological order is simply row by row
        for r in range(n):
            for c in range(len(triangle[r])):
                if (r, c) not in dist:
                    continue
                for v, w in graph[(r, c)]:
                    new_dist = dist[(r, c)] + w
                    if v not in dist or new_dist < dist[v]:
                        dist[v] = new_dist
        
        # Answer = min dist among last row nodes
        last_row = [(n - 1, c) for c in range(n)]
        return min(dist[v] for v in last_row)

