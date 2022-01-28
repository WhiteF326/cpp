import java.util.*;
import java.io.*;

public class Main {
  static class FastScanner {
    private BufferedReader reader = null;
    private StringTokenizer tokenizer = null;

    public FastScanner(InputStream in) {
      reader = new BufferedReader(new InputStreamReader(in));
      tokenizer = null;
    }

    public String next() {
      if (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public String nextLine() {
      if (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          return reader.readLine();
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }

      return tokenizer.nextToken("\n");
    }

    public long nextLong() {
      return Long.parseLong(next());
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public double nextDouble() {
      return Double.parseDouble(next());
    }

    public int[] nextIntArray(int n) {
      int[] a = new int[n];
      for (int i = 0; i < n; i++)
        a[i] = (int) nextInt();
      return a;
    }

    public long[] nextLongArray(int n) {
      long[] a = new long[n];
      for (int i = 0; i < n; i++)
        a[i] = nextLong();
      return a;
    }
  }

  public static void main(String[] args) {
    FastScanner fs = new FastScanner(System.in);
    String s = fs.next();
    int n = s.length();

    int ans = 0;
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j <= n; j++){
        String t = s.substring(i, j);
        boolean flg = true;
        for(int k = 0; k < t.length(); k++){
          if(t.charAt(k) != 'A' && t.charAt(k) != 'C' && t.charAt(k) != 'T' && t.charAt(k) != 'G'){
            flg = false;
          }
        }
        if(flg){
          if(ans < t.length()) ans = t.length();
        }
      }
    }

    System.out.println(ans);
  }
}
