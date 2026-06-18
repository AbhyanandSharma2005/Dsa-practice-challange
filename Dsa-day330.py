class Solution:
    def angleClock(self, hr: int, mins: int) -> float:
        min_hand = mins * 6
        hr_hand = hr * 30 + mins * 0.5
        res = abs(hr_hand - min_hand)
        if res > 180:
            return 360 - res
        else:
            return res