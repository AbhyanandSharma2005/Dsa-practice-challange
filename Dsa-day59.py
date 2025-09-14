class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        words = set(wordlist)
        cap_map = {}
        vowel_map = {}
        vowels = set('aeiou')

        def devowel(word):
            return ''.join('*' if c in vowels else c for c in word)

        for w in wordlist:
            lw = w.lower()
            if lw not in cap_map:
                cap_map[lw] = w
            vw = devowel(lw)
            if vw not in vowel_map:
                vowel_map[vw] = w

        res = []
        for q in queries:
            if q in words:
                res.append(q)
                continue
            lq = q.lower()
            if lq in cap_map:
                res.append(cap_map[lq])
                continue
            vq = devowel(lq)
            if vq in vowel_map:
                res.append(vowel_map[vq])
            else:
                res.append("")
        return res
