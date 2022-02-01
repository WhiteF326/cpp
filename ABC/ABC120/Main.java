import java.util.*;
import java.io.*;

class UnionFind {
  int[] parent;
  int[] rank;
  int[] size;

  public UnionFind(int n) {
    this.parent = new int[n];
    this.rank = new int[n];
    this.size = new int[n];

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
      size[i] = 1;
    }
  }

  public int find(int x) {
    if (x == parent[x]) {
      return x;
    } else {
      parent[x] = find(parent[x]);
      return parent[x];
    }
  }

  public boolean same(int x, int y) {
    return find(x) == find(y);
  }

  public void merge(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);

    if (xRoot == yRoot) {
      return;
    }

    if (rank[xRoot] > rank[yRoot]) {
      parent[yRoot] = xRoot;
      size[xRoot] += size[yRoot];
    } else if (rank[xRoot] < rank[yRoot]) {
      parent[xRoot] = yRoot;
      size[yRoot] += size[xRoot];
    } else {
      parent[xRoot] = yRoot;
      size[yRoot] += size[xRoot];
      rank[xRoot]++;
    }
  }

  public int size(int x){
    return size[find(x)];
  }
}

class FastScanner {
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

class FastPrinter implements Closeable {
  private PrintWriter printWriter = null;

  public FastPrinter(OutputStream outputStream) {
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

  void printf(String format, Object... args) {
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

  void flush() {
    printWriter.flush();
  }

  public void close() {
    printWriter.flush();
    printWriter.close();
  }
}

public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner(System.in);
    FastPrinter out = new FastPrinter(System.out);

    int n = Integer.parseInt(sc.next());
    int m = Integer.parseInt(sc.next());

    int[][] path = new int[m][2];

    for(int i = 0; i < m; i++){
      path[m - 1 - i][0] = Integer.parseInt(sc.next()) - 1;
      path[m - 1 - i][1] = Integer.parseInt(sc.next()) - 1;
    }
    long ans = 1L * n * (n - 1) / 2L;
    Stack<Long> anslist = new Stack<>();
    UnionFind d = new UnionFind(n);

    for(int i = 0; i < m; i++){
      anslist.add(ans);
      if(d.same(path[i][0], path[i][1])){
        continue;
      }
      long left = (long)d.size(path[i][0]);
      long right = (long)d.size(path[i][1]);
      ans = Math.max(ans - left * right, 0L);
      d.merge(path[i][0], path[i][1]);
    }

    for(int i = 0; i < m; i++){
      out.println(anslist.pop());
    }

    out.close();
  }
}