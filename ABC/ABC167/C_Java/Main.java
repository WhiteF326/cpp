package ABC.ABC167.C_Java;
import java.util.*;

class Main {

    static double log2(double x){
        return Math.log10(x) / Math.log10(2);
    }

    static int[] Dec2Bin(int x, int len){
        String l = Integer.toBinaryString(x);
        int[] ret = new int[len];
        for(int i = 0; i < l.length(); i++){
            ret[len - l.length() + i] = Integer.parseInt(l.substring(i, i + 1));
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int[][] ca = new int[n][m + 1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m + 1; j++){
                ca[i][j] = sc.nextInt();
            }
        }
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < Math.pow(2, n); i++){
            int[] searchBin = Dec2Bin(i, n);
            int[] res = new int[m];
            int money = 0;
            for(int j = 0; j < n; j++){
                if(searchBin[j] == 0) continue;
                money += ca[j][0];
                for(int k = 0; k < m; k++){
                    res[k] += ca[j][k + 1];
                }
            }
            boolean tmp = true;
            for(int j = 0; j < m; j++){
                if(res[j] < x) tmp = false;
            }
            if(tmp) ans = Math.min(ans, money);
        }
        System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
        sc.close();
        return;
    }
}
