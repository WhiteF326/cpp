import java.util.*;

class Main{
  static final long modv = 998244353;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    long[] a = new long[n];
    for(int i = 0; i < n; i++) a[i] = Long.parseLong(sc.next());

    long[][] dp = new long[n][10];
    dp[0][(int)a[0]] = 1;
    for(int i = 0; i < n - 1; i++){
      for(int j = 0; j <= 9; j++){
        if(dp[i][j] == 0) continue;
        dp[i + 1][(int)((j + a[i + 1]) % 10)] = 
          (dp[i + 1][(int)((j + a[i + 1]) % 10)] + dp[i][j]) % modv;
        dp[i + 1][(int)((j * a[i + 1]) % 10)] = 
          (dp[i + 1][(int)((j * a[i + 1]) % 10)] + dp[i][j]) % modv;
      }
    }

    for(int i = 0; i <= 9; i++){
      System.out.println(dp[n - 1][i]);
    }

    sc.close();
  }
}