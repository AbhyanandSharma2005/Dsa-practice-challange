class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.ans=True
        def sear(r,h):
            if r:
                h+=1
                a=sear(r.left,h)
                b=sear(r.right,h)
                d=abs(b-a)
                if d>1:self.ans=False
                return max(a,b,h)
            else:return h
        sear(root,0)
        return self.ans