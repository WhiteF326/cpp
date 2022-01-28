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

  static int max(int a, int b){
    if(a > b) return a;
    else return b;
  }

  public static void main(String[] args) {
    FastScanner fs = new FastScanner(System.in);
    int n = fs.nextInt();

    int[] l = new int[n];

    for(int i = 0; i < n; i++){
      l[i] = fs.nextInt();
    }

    int ans = 0;

    for(int i = 0; i < n - 2; i++){
      for(int j = i + 1; j < n - 1; j++){
        for(int k = j + 1; k < n; k++){
          if(l[i] == l[j] || l[j] == l[k] || l[i] == l[k]) continue;
          int x = max(l[i], max(l[j], l[k]));
          if(x < l[i] + l[j] + l[k] - x) ans++;
        }
      }
    }

    System.out.println(ans);
  }
}
