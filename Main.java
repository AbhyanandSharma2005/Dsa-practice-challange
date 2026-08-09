import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null) return;
        int t = Integer.parseInt(line.trim());
        StringBuilder sb = new StringBuilder();
        
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String s = br.readLine().trim();
            
            int w0 = 0, w1 = 0;
            boolean v00 = true, v01 = true, v10 = true, v11 = true;
            
            for (int i = 0; i < n; i += 2) {
                char c = s.charAt(i);
                if (c != '?') {
                    char e0 = ((i / 2) % 2 == 0) ? '0' : '1';
                    char e1 = ((i / 2) % 2 == 0) ? '1' : '0';
                    if (c != e0) v00 = false;
                    if (c != e1) v01 = false;
                }
            }
            
            for (int i = 1; i < n; i += 2) {
                char c = s.charAt(i);
                if (c != '?') {
                    char e0 = (((i - 1) / 2) % 2 == 0) ? '0' : '1';
                    char e1 = (((i - 1) / 2) % 2 == 0) ? '1' : '0';
                    if (c != e0) v10 = false;
                    if (c != e1) v11 = false;
                }
            }
            
            if (v00) w0++;
            if (v01) w0++;
            if (v10) w1++;
            if (v11) w1++;
            
            sb.append((w0 * w1) % 998244353).append("\n");
        }
        System.out.print(sb);
    }
}