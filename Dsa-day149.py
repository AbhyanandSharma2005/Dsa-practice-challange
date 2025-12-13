class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        order = {"electronics": 0, "grocery": 1, "pharmacy": 2, "restaurant": 3}
        candidates = []
        for i in range(len(code)):
            if (code[i] and 
                isActive[i] and 
                businessLine[i] in order and 
                all(c.isalnum() or c == '_' for c in code[i])):
                candidates.append((order[businessLine[i]], code[i]))
        candidates.sort()
        return [code_val for _, code_val in candidates]