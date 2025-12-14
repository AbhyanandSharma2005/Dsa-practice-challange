class Solution:
    def numberOfWays(self, corridor: str) -> int:
        pre_check = corridor.count("S")
        if pre_check < 2 or (pre_check % 2 == 1):
            return 0
        elif pre_check == 2:
            return 1

        segments = 1
        plants = 0
        seats = 0
                
        for i in range(len(corridor)):
            if corridor[i] == "S":
                seats += 1
                if seats == 2:
                    if plants > 0:
                        segments = (segments * (plants + 1)) % (10**9 + 7)
                    plants = 0
                elif seats > 2:
                    seats = 1
            else:
                if seats == 2:
                    plants += 1
        return segments
        