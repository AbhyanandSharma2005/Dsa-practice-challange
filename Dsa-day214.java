class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        int arr[] = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
        List<String> strr = new ArrayList<>();
        func(strr, arr, turnedOn, 0, 0, 0);
        return strr;
    }
    public void func(List<String> strr, int[] arr, int i, int ind, int hr, int min){
        if(i == 0){
            if(hr > 11 || min > 59)
                return;
            String ans = String.valueOf(hr);
            ans = ans + ':';
            if(min < 10){
                ans = ans + '0';
            }
            ans = ans + String.valueOf(min);
            strr.add(ans);
            return;
        }

        if (ind > 9) 
            return;

        func(strr, arr, i, ind + 1, hr, min);
            if(ind <= 3){
                func(strr, arr, i - 1, ind + 1, hr + arr[ind], min);
            }
            else{
                func(strr, arr, i - 1, ind + 1, hr, min + arr[ind]);
            }
        
        return;
    }
}