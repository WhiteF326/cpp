import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    String x = sc.next();
    int n = Integer.parseInt(sc.next());
    String[] s = new String[n];
    for(int i = 0; i < n; i++){
      s[i] = sc.next();
    }

    String[] t = new String[n];
    for(int i = 0; i < n; i++){
      t[i] = "";
      for(int j = 0; j < s[i].length(); j++){
        t[i] += (char)('a' + x.indexOf(s[i].charAt(j)));
      }
    }

    Arrays.sort(t);
    for(int i = 0; i < n; i++){
      StringBuilder stbl = new StringBuilder();
      for(int j = 0; j < t[i].length(); j++){
        stbl.append(x.charAt(t[i].charAt(j) - 'a'));
      }
      System.out.println(stbl);
    }

    sc.close();
  }
}
