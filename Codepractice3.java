import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int t = sc.nextInt();
            while (t-- > 0) {
                int n = sc.nextInt();
                int[] a = new int[n];
                for (int i = 0; i < n; i++) {
                    a[i] = sc.nextInt();
                }
                Arrays.sort(a);
                boolean hasDuplicate = false;
                for (int i = 0; i < n - 1; i++) {
                    if (a[i] == a[i + 1]) {
                        hasDuplicate = true;
                        break;
                    }
                }
                if (hasDuplicate) {
                    System.out.println("-1");
                } else {
                    StringBuilder sb = new StringBuilder();
                    for (int i = n - 1; i >= 0; i--) {
                        sb.append(a[i]).append(" ");
                    }
                    System.out.println(sb.toString().trim());
                }
            }
        }
        sc.close();
    }
}d