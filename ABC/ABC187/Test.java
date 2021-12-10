import java.util.*;
import java.io.*;

public class Test {

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

  public static class Sort implements Comparable<Sort> {
    int a, b;

    public Sort(int a, int b) {
      this.a = a;
      this.b = b;
    }

    public long getEfficiency(){
      return (long)a * 2 + (long)b;
    }

    public int compareTo(Sort num) {
      if(num.getEfficiency() > this.getEfficiency()) return 1;
      else if(num.getEfficiency() < this.getEfficiency()) return -1;
      else return 0;
    }
  }

  public static void main(String[] args) throws FileNotFoundException {
    FastScanner sc = new FastScanner(System.in);
    int n = sc.nextInt();
    Sort[] sort = new Sort[n];
    long aoki = 0;
    for (int i = 0; i < n; i++) {
      int a = sc.nextInt(), b = sc.nextInt();
      aoki += a;
      sort[i] = new Sort(a, b);
    }
    Arrays.sort(sort);
    int ans = 0;
    long suma = aoki, sumb = 0;
    for (Sort s : sort) {
      if (sumb > suma) {
        break;
      }
      suma -= s.a;
      sumb += s.a + s.b;
      ans++;
    }
    System.out.println(ans);
  }
}