class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        Arrays.sort(meetings,(a,b)-> a[2]-b[2]);

        int[] parent =new int[n];
        boolean[] secret = new boolean[n];
        for(int i=0;i<n; i++)parent[i]=i;

        secret[0] = secret[firstPerson]=true;
        for(int i=0;i<meetings.length;){
            int time =meetings[i][2];
            Set<Integer> group = new HashSet<>();

            int j=i;
            while(j<meetings.length && meetings[j][2] == time){
                union(meetings[j][0],meetings[j][1],parent);
                group.add(meetings[j][0]);
                group.add(meetings[j][1]);
                j++;
            }
            for(int p:group)
            if(secret[p])
            secret[find(p,parent)] = true;

            for(int p:group)
            secret[p]=secret[find(p,parent)];

            for(int p:group)
            parent[p]=p;

            i=j;
        }

        List<Integer> ans =new ArrayList<>();
        for(int i=0;i<n;i++){
            if(secret[i])ans.add(i);
        }
        return ans;
    }
        private int find (int x, int[] p){
            return p[x] == x?x : (p[x] =find(p[x],p));
        }
        private void union(int a, int b,int[] p){
            p[find(b,p)]=find(a,p);
        }
    
}