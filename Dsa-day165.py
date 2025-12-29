class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        trans = defaultdict(list)
        for s in allowed:
            trans[s[:2]].append(s[2])
        
        memo = set()
        
        def dfs(row: str) -> bool:
            if len(row) == 1:
                return True
            if row in memo:
                return False
            
            next_rows = []
            def build(idx: int, path: list):
                if idx == len(row) - 1:
                    next_rows.append(''.join(path))
                    return
                key = row[idx:idx+2]
                if key not in trans:
                    return
                for c in trans[key]:
                    path.append(c)
                    build(idx + 1, path)
                    path.pop()
            
            build(0, [])
            
            for nxt in next_rows:
                if dfs(nxt):
                    return True
            
            memo.add(row)
            return False
        
        return dfs(bottom)