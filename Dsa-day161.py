class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        max_happiness = 0
        happiness.sort(reverse=True)

        i = 0
        while k !=0 :
            happiness_value = happiness[i] - i
            if happiness_value <= 0 :
                break
            max_happiness += happiness_value
            i += 1
            k -= 1

        return max_happiness