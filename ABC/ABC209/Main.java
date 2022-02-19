import java.util.*;
import java.io.*;

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

  void println(){
    printWriter.println();
  }

  void flush() {
    printWriter.flush();
  }

  public void close() {
    printWriter.flush();
    printWriter.close();
  }
}

class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner(System.in);
    FastPrinter out = new FastPrinter(System.out);

    int n = sc.nextInt();
    int q = sc.nextInt();

    ArrayList<ArrayList<Integer>> g = new ArrayList<>();
    for(int i = 0; i < n; i++){
      g.add(new ArrayList<>());
    }
    for(int i = 0; i < n - 1; i++){
      int a = sc.nextInt();
      int b = sc.nextInt();
      g.get(a - 1).add(b - 1);
      g.get(b - 1).add(a - 1);
    }

    ArrayDeque<Integer> que = new ArrayDeque<>();
    que.add(0);
    boolean[] visited = new boolean[n];
    visited[0] = true;
    int[] dist = new int[n];
    dist[0] = 0;
    while(!que.isEmpty()){
      int cur = que.poll();
      for(int next : g.get(cur)){
        if(!visited[next]){
          visited[next] = true;
          dist[next] = dist[cur] + 1;
          que.add(next);
        }
      }
    }

    for(int i = 0; i < q; i++){
      int a = sc.nextInt();
      int b = sc.nextInt();
      out.println((dist[a - 1] + dist[b - 1]) % 2 == 0 ? "Town" : "Road");
    }

    // you solved ABC209 D! you're insane!

    out.close();
  }
}
