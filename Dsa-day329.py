import re
class Solution:
    def processStr(self, s: str) -> str:
        ans=""
        if(bool(re.search(r'[a-zA-Z]', s))):
            for i in s:
                if(i=='#'):
                    ans+=ans
                if(i=='%'):
                    ans=ans[::-1]
                if(i=='*'):
                    ans=ans[:-1]
                if(i.isalpha()):
                    ans+=i
        return ans