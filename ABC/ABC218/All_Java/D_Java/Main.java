package D_Java;
import java.util.*;
import java.io.*;

class Main {
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

  static Long poscal(int[] x) {
    return (long) x[1] * 1000000000L + (long) x[0];
  }

  public static void main(String[] args) {
    FastScanner sc = new FastScanner(System.in);

    int n = sc.nextInt();
    int[][] points = new int[n][2];
    HashSet<Long> pls = new HashSet<>();

    for (int i = 0; i < n; i++) {
      int x = sc.nextInt(), y = sc.nextInt();
      points[i][0] = x;
      points[i][1] = y;
      pls.add(poscal(points[i]));
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        int[] p1 = points[i];
        int[] p2 = points[j];
        // x軸かy軸上で同じ位置にあるなら飛ばす
        if (p1[0] == p2[0] || p1[1] == p2[1])
          continue;
        // 欲しい点を求める
        int[] p3 = { p1[0], p2[1] };
        int[] p4 = { p2[0], p1[1] };
        long p3c = poscal(p3);
        long p4c = poscal(p4);

        if (pls.contains(p3c) && pls.contains(p4c)) {
          ans++;
        }
      }
    }

    System.out.println(ans / 2);
  }
}