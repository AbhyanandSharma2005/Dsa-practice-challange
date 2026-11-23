class ProductOfNumbers:
    __slots__ = ('p',)  

    def __init__(self):
        self.p = [1]

    def add(self, num: int) -> None:
        if num:
            self.p.append(self.p[-1] * num)
        else:
            self.p = [1]

    def getProduct(self, k: int) -> int:
        p = self.p  
        return 0 if k >= len(p) else p[-1] // p[-k - 1]