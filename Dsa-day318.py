### Dynamic Programming
memo = [0]
for n in range(1,10**5+1):
    num = str(n)
    l = len(num)
    if n <= 2: memo.append(0)
    else:
        waves = 0
        i = 0
        j = 2
        while i < j and j < l:
            if num[i] < num[i+1] > num[j] or num[i] > num[i+1] < num[j]:
                waves += 1
            i += 1
            j += 1
        memo.append(waves)
waveCount = []
count = 0
for n in memo:
    count += n
    waveCount.append(count)
class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        return waveCount[num2] - waveCount[num1 - 1]