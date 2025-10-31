class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        Map<Integer,Integer> map = new HashMap<>();
        int[] res = new int[2];
        int i = 0;
        for(int x : nums){
            map.put(x, map.getOrDefault(x,0)+1);
            if(map.get(x)==2) res[i++] = x;
        }
        return res;
    }
}
