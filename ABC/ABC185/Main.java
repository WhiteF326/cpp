import java.util.*;
import java.io.*;

interface Monoid<T> {
  public T op(T a, T b);

  public T e();
}

class SegTree<T> {
  private ArrayList<T> v = new ArrayList<>();
  private int n;
  private Monoid<T> monoid;

  SegTree(int n, Monoid<T> monoid) {
    this.n = 1;
    while (this.n < n)
      this.n *= 2;
    v.ensureCapacity(this.n * 4);

    this.monoid = monoid;

    for (int i = 0; i < this.n * 4; i++) {
      v.add(monoid.e());
    }
  }

  public void set(int p, T value) {
    int np = p + this.n - 1;
    v.set(np, value);
    while (np > 0) {
      np = (np - 1) / 2;
      v.set(np, monoid.op(v.get(np * 2 + 1), v.get(np * 2 + 2)));
    }
  }

  public T get(int p) {
    return v.get(p + this.n - 1);
  }

  public T query(int l, int r) {
    return subquery(l, r, 0, 0, this.n);
  }

  private T subquery(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return monoid.e();
    } else if (a <= l && r <= b) {
      return v.get(k);
    } else {
      T vl = subquery(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = subquery(a, b, k * 2 + 2, (l + r) / 2, r);
      return monoid.op(vl, vr);
    }
  }

  ArrayList<T> retAry() {
    return v;
  }
}

class Xor implements Monoid<Long> {
  public Long op(Long a, Long b) {
    return a ^ b;
  }

  public Long e() {
    return 0L;
  }
}

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

  static class FastPrinter implements Closeable {
    private PrintWriter printWriter = null;

    public FastPrinter(OutputStream outputStream){
      printWriter = new PrintWriter(outputStream);
    }

    void print(boolean x) {
      printWriter.println(x);
    }
    void print(char x) {
      printWriter.print(x);
    }
    void print(char[] x) {
      printWriter.print(x);
    }
    void print(double x) {
      printWriter.print(x);
    }
    void print(float x) {
      printWriter.print(x);
    }
    void print(int x) {
      printWriter.print(x);
    }
    void print(long x) {
      printWriter.print(x);
    }
    void print(Object x) {
      printWriter.print(x);
    }
    void print(String x) {
      printWriter.print(x);
    }
    void printf(String format, Object... args){
      printWriter.printf(format, args);
    }
    void println(boolean x) {
      printWriter.println(x);
    }
    void println(char x) {
      printWriter.println(x);
    }
    void println(char[] x) {
      printWriter.println(x);
    }
    void println(double x) {
      printWriter.println(x);
    }
    void println(float x) {
      printWriter.println(x);
    }
    void println(int x) {
      printWriter.println(x);
    }
    void println(long x) {
      printWriter.println(x);
    }
    void println(Object x) {
      printWriter.println(x);
    }
    void println(String x) {
      printWriter.println(x);
    }
    void flush(){
      printWriter.flush();
    }

    public void close(){
      printWriter.flush();
      printWriter.close();
    }
  }

  public static void main(String[] args) {
    FastScanner sc = new FastScanner(System.in);
    FastPrinter out = new FastPrinter(System.out);

    int n = Integer.parseInt(sc.next());
    int q = Integer.parseInt(sc.next());

    Long[] a = new Long[n];
    for (int i = 0; i < n; i++) {
      a[i] = Long.parseLong(sc.next());
    }

    SegTree<Long> segTree = new SegTree<>(n, new Xor());
    for (int i = 0; i < n; i++) {
      segTree.set(i, a[i]);
    }

    for (int i = 0; i < q; i++) {
      int t = Integer.parseInt(sc.next());
      if (t == 1) {
        int x = Integer.parseInt(sc.next());
        Long y = Long.parseLong(sc.next());
        segTree.set(x - 1, segTree.get(x - 1) ^ y);
      } else {
        int x = Integer.parseInt(sc.next());
        int y = Integer.parseInt(sc.next());
        out.println(segTree.query(x - 1, y));
      }
    }

    out.close();
  }
}