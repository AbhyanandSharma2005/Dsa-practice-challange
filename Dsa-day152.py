class Solution:
    def maxProfit(self,n,p,f,h,b):
        g=[[]for _ in range(n+1)];st,ord,dp=[1],[],[0]*(n+1)
        for u,v in h:g[u].append(v)
        while st:u=st.pop();ord.append(u);st+=g[u][::-1]
        for u in ord[::-1]:
            g0=g1=[0]
            for v in g[u]:
                f0,f1=dp[v];dp[v]=0
                def mg(a,c):
                    m=min(b,len(a)+len(c)-2)+1;r=[-1]*m
                    for i,x in enumerate(a):
                        if x<0:continue
                        for j,y in enumerate(c[:m-i]):
                            if y>=0:r[i+j]=max(r[i+j],x+y)
                    return r
                g0,g1=mg(g0,f0),mg(g1,f1)
            c=p[u-1];pf,ph=f[u-1]-c,f[u-1]-c//2
            def mk(g0,g1,c,pf):
                m=min(b,max(len(g0)-1,len(g1)-1+c))+1; r=[-1]*m
                for i in range(min(m,len(g0))):r[i]=g0[i]
                for i in range(len(g1)):
                    if i+c<m and g1[i]>=0:r[i+c]=max(r[i+c],g1[i]+pf)
                return r
            dp[u]=(mk(g0,g1,c,pf),mk(g0,g1,c//2,ph))
        return max(dp[1][0])