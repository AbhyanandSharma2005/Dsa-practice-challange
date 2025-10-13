class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        if not words:
            return []
        
        result = []
        prev_sorted_word = ""

        for word in words:
            current_sorted_word = "".join(sorted(word))
            
            if current_sorted_word != prev_sorted_word:
                result.append(word)
                prev_sorted_word = current_sorted_word
                
        return result