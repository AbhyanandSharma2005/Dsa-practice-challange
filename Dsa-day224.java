class Solution {
    public int minOperations(String s, int k) {
        int zero = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '0') zero++;
        }
        int totalOneAndZero = s.length();
        if(zero == k) return 1;
        if(zero == 0) return 0;

        Integer[] step = new Integer[totalOneAndZero + 1];
        Arrays.fill(step, -1);

        TreeSet<Integer> evenCount = new TreeSet<>();
        TreeSet<Integer> oddCount = new TreeSet<>();

        for(int i = 0; i <= totalOneAndZero; i++) {
            if(i % 2 == 0) evenCount.add(i);
            else oddCount.add(i);
        }

        Queue<int[]> que = new LinkedList<>();//  [zeroCountNow, step]
        que.offer(new int[]{zero, 0});
        step[zero] = 0;

        if(zero % 2 == 0) evenCount.remove(zero);
        else oddCount.remove(zero);

        // two examples
        // if n = 7 zero = 5 and k is 4
        // if n = 7 zero = 2 and k is 4

        while(!que.isEmpty()) {
            // if k is 4
            int[] zeroNow = que.poll(); // [current zero count, step]

            // if n = 7 zero = 5 then min zero can flip is 0
            // if zero = 2 then min zero can flip is 0 maximum of (0, 4 - (7 - 2)) == (0, -1) 
            //either we can flip [0 1 2] cant flip -1 count
            int minZeroCanFlip = Math.max(0, k - (totalOneAndZero - zeroNow[0]));
            // if n = 7 zero = 5 then max zero can flip is 4 minimum of (4,5)
            // if zero = 2 then max zero can flip is 2 minimum of (2,4)
            int maxZeroCanFlip = Math.min(k, zeroNow[0]);

            // so if we check range n = 7, zero = 5, k = 4 range of zeroFlip will be [0,1,2,3,4] - (for this do manual like i have done for other example)
            // if we check range n = 7, zero = 2, k = 4 range of zeroFlip will be [0,1,2]

            // so the my countOfZeroRemovalRange will become for ex- n = 7, zero = 2, k = 4 is [0,1,2]
            // if choose to flip 0 count 0f zero then (k - 0) count of 1 will flip to zero
            //similarly 1 count of zero flip to 1 then (k - 1) flipped to zero

            // so my new range of zero will be zeroNow[0] - maxZeroCanFlip + k - maxZeroCaFlip
            // zeroNow[0] + k - 2 * (maxZeroCanFlip) = leftBound --> 2 - 2 + (4 - 2) = 2
            // 2 - 1 + (4 - 1) = 4
            // zeroNow[0] + k - 2 * (minZeroCanFlip) = rightBound --> 2 - 0 + (4 - 0) = 6
            int leftBound = zeroNow[0] + k - (2 * maxZeroCanFlip);
            int rightBound = zeroNow[0] + k - (2 * minZeroCanFlip);
            // if we see pattern left and right is even, similarly for other example it will be odd

            // now if we have already achieved zeroCount at minstep no need to visit it again 
            //so if we keep in treeset and check if it is there skip it or what we can do remove 
            //if we reach at zeroCount at minstep

            TreeSet<Integer> currentSet = (leftBound % 2 == 0) ? evenCount : oddCount;

            // so from intitaly zeroCount was 2 then 2 -> 4 count can reach at step[2] + 1
            // similarly 2 -> 6 count at step[2] + 1 update the step value and remove from treeset, no need to visit these numbers again 

            //[2,4,6]
            Integer zeroCountRange = currentSet.ceiling(leftBound);

            while(zeroCountRange != null && zeroCountRange <= rightBound) {
                
                step[zeroCountRange] = step[zeroNow[0]] + 1;

                if(zeroCountRange == 0) return step[zeroCountRange];
                currentSet.remove(zeroCountRange);
                que.offer(new int[] {zeroCountRange, step[zeroCountRange]});

                zeroCountRange = currentSet.ceiling(zeroCountRange);
            }

        }
        return -1;
    }
}