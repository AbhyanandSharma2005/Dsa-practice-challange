from collections import defaultdict

class Solution:
    def remainingMethods(self, n, k, invocations):
        
        invoke_graph = defaultdict(list)    
        reverse_graph = defaultdict(list)   
        
        for a, b in invocations:
            invoke_graph[a].append(b)
            reverse_graph[b].append(a)
        
        
        suspicious = set()
        
        def dfs(method):
            if method in suspicious:
                return
            suspicious.add(method)
            for neighbor in invoke_graph[method]:
                dfs(neighbor)
        
        dfs(k)
        
        
        for method in suspicious:
            for invoker in reverse_graph[method]:
                if invoker not in suspicious:
                    
                    return list(range(n))
        
        
        remaining_methods = [i for i in range(n) if i not in suspicious]
        return remaining_methods

n = 4
k = 1
invocations = [[1, 2], [0, 1], [3, 2]]
solution = Solution()
print(solution.remainingMethods(n, k, invocations))  # Output: [0, 1, 2, 3]

n = 5
k = 0
invocations = [[1, 2], [0, 2], [0, 1], [3, 4]]
print(solution.remainingMethods(n, k, invocations))  # Output: [3, 4]

n = 3
k = 2
invocations = [[1, 2], [0, 1], [2, 0]]
print(solution.remainingMethods(n, k, invocations))  # Output: []