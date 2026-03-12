from typing import List

class DSU:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.size = [1] * n
        self.components = n

    def find(self, x: int) -> int:
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def join(self, x: int, y: int) -> bool:
        px = self.find(x)
        py = self.find(y)

        if px != py:
            if self.size[px] < self.size[py]:
                px, py = py, px  
            
            self.parent[py] = px
            self.size[px] += self.size[py]
            self.components -= 1
            return True
        return False


class Solution:
    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        dsu = DSU(n)
        min_stability = float("inf")
        optional = []
        
        for index, edge in enumerate(edges):
            u, v, weight, must = edge
            if must:
                if dsu.join(u, v):
                    min_stability = min(min_stability, weight)
                else:
                    return -1
            else:
                optional.append(index)

        if dsu.components == 1:
            return min_stability if min_stability != float('inf') else 0

        optional.sort(key=lambda x: edges[x][2], reverse=True)

        stabilities = []
        for index in optional:
            u, v, weight, must = edges[index]
            if dsu.join(u, v):
                stabilities.append(weight)
                if dsu.components == 1:
                    break

        if dsu.components > 1:
            return -1

        for i in range(1, min(len(stabilities), k) + 1):
            stabilities[-i] *= 2

        return min(min(stabilities), min_stability)