# Last updated: 6/10/2026, 7:25:40 PM
class Solution:
    def findOrder(self, n: int, edges: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]
        indeg = [0] * n

        for u , v in edges:
            adj[v].append(u)
            indeg[u] += 1
        
        q = deque()
        for u in range(n):
            if indeg[u] == 0:
                q.append(u)
        
        ans = []

        while q:
            u = q.popleft()
            ans.append(u)

            for v in adj[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)

        return ans if len(ans) == n else []