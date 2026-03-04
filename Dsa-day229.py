class Solution:
    def trav(self, i: int, j: int, mat: List[List[int]]) -> bool:
        specialCnt = 0
        for n in range(0, len(mat)):
            if mat[n][j] == 1:
                specialCnt+=1
            if specialCnt > 1:
                return False
        for n in range(0, len(mat[0])):
            if mat[i][n] == 1:
                specialCnt+=1
            if specialCnt > 2:
                return False
        return True

    def numSpecial(self, mat: List[List[int]]) -> int:
        totalSpecial = 0
        for i in range(0, len(mat)):
            for j in range(0, len(mat[0])):
                if mat[i][j] == 1 and self.trav(i, j, mat):
                    totalSpecial+=1
        return totalSpecial

                    