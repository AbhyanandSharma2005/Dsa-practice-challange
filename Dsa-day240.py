class Fancy:

    def __init__(self):
        self.seq = []
        self.currLen = 0
        self.MOD = 10 ** 9 + 7
        self.addModifiers = [0]
        self.multModifiers = [1]

    def append(self, val: int) -> None:
        self.addModifiers.append(self.addModifiers[-1])
        self.multModifiers.append(self.multModifiers[-1])
        self.seq.append(val)
        self.currLen += 1

    def addAll(self, inc: int) -> None:
        self.addModifiers[-1] += inc

    def multAll(self, m: int) -> None:
        self.multModifiers[-1] *= m
        self.addModifiers[-1] *= m

    def getIndex(self, idx: int) -> int:
        if idx >= self.currLen: return -1
        res = self.seq[idx]

        multMod = self.multModifiers[-1] // self.multModifiers[idx]
        addMod = self.addModifiers[-1] - self.addModifiers[idx] * multMod
        res *= multMod
        res += addMod

        return res % self.MOD

# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)