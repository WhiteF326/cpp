package ABC.ABC195.C_Java;
import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long ans = 0;
        int maxc = (int)(Math.log10(n) / 3);
        for(int i = 1; i <= maxc; i++){
            ans += ((long)Math.min((long)Math.pow(10, (i + 1) * 3) - 1, n) - ((long)Math.pow(10, i * 3) - 1)) * i;
        }
        System.out.println(ans);
        sc.close();
    }
}