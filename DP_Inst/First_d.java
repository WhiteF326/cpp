import java.util.*;

public class First_d {
  public static void main(String[] args) {
    // n 個の品物(items に価値を格納) から任意の個数選ぶ
    // 価値の総和が k を超えないうちで最高になるような組み合わせにおける、価値の総和を答える

    Scanner sc = new Scanner(System.in);

    int n = Integer.parseInt(sc.next());
    int k = Integer.parseInt(sc.next());
    int[] items = new int[n];
    for(int i = 0; i < n; i++) items[i] = Integer.parseInt(sc.next());

    final int limit = 100000;

    boolean[][] dp = new boolean[n + 1][limit + 1];
    dp[0][0] = true;
    for(int i = 0; i < n; i++){
      for(int j = 0; j <= limit; j++){
        if(!dp[i][j]) continue;
        // i 番目の品物を選ぶ場合
        dp[i + 1][j + items[i]] = true;
        // 選ばない場合
        dp[i + 1][j] = true;
      }
    }

    int ans = 0;
    for(int i = 0; i <= k; i++){
      if(dp[n][i]) ans = i;
    }
    System.out.println(ans);

    sc.close();
  }
}