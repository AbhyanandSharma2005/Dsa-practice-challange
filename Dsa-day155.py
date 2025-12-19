class UnionFind:
    def __init__(self, n: int):
        """
        Union-Find (Disjoint Set Union) data structure.
        
        Args:
            n: Number of elements
        """
        self.parent = list(range(n))
        self.rank = [0] * n
    
    def find(self, x: int) -> int:
        """
        Find root of x with path compression.
        
        Args:
            x: Element to find
            
        Returns:
            Root of x
        """
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x: int, y: int) -> None:
        """
        Union two elements by rank.
        
        Args:
            x: First element
            y: Second element
        """
        root_x = self.find(x)
        root_y = self.find(y)
        
        if root_x == root_y:
            return
        
        if self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        elif self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1
    
    def connected(self, x: int, y: int) -> bool:
        """
        Check if two elements are connected.
        
        Args:
            x: First element
            y: Second element
            
        Returns:
            True if connected, False otherwise
        """
        return self.find(x) == self.find(y)
    
    def reset(self, x: int) -> None:
        """
        Reset element x to be its own component.
        
        Args:
            x: Element to reset
        """
        self.parent[x] = x
        self.rank[x] = 0


class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        """
        Find all people who eventually know the secret.
        
        Secret starts from person 0 and firstPerson.
        Meetings happen at specific times between two people.
        If one person knows secret before meeting, both know after.
        
        Args:
            n: Number of people
            meetings: List of [x, y, time] meetings
            firstPerson: Person who knows secret initially with person 0
            
        Returns:
            List of people who eventually know the secret
        """
        uf = UnionFind(n)
        
        uf.union(0, firstPerson)
        
        time_groups = {}
        for x, y, time in meetings:
            if time not in time_groups:
                time_groups[time] = []
            time_groups[time].append((x, y))
        
        for time in sorted(time_groups.keys()):
            pairs = time_groups[time]
            people_involved = set()
            
            for x, y in pairs:
                uf.union(x, y)
                people_involved.add(x)
                people_involved.add(y)
            
            for person in people_involved:
                if not uf.connected(person, 0):
                    uf.reset(person)
        
        result = []
        for i in range(n):
            if uf.connected(i, 0):
                result.append(i)
        
        return result