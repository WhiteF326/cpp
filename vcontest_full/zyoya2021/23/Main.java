import java.util.HashSet;
import java.util.Scanner;
import java.util.Arrays;

public class Main {
  static int k = 0;
  static String s = "";
  static int[] perm = new int[8];
  static boolean[] used = new boolean[8];
  static HashSet<String> st = new HashSet<>();
  static StringBuilder stbl = new StringBuilder();

  static void dfs(int p, int d){
    if(d == s.length() - 1){
      st.add(stbl.toString() + s.charAt(p));
      return;
    }
    used[p] = true;
    stbl.append(s.charAt(p));
    for(int i = 0; i < s.length(); i++){
      if(used[i]) continue;
      dfs(i, d + 1);
    }
    used[p] = false;
    stbl.setLength(stbl.length() - 1);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    s = sc.next();
    k = sc.nextInt();

    sc.close();
    
    for(int i = 0; i < s.length(); i++){
      dfs(i, 0);
    }

    Object[] x = st.toArray();
    Arrays.sort(x);
    System.out.println(x[k - 1]);
  }
}
