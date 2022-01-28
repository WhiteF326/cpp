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
    
    HashMap<String, Integer> hs = new HashMap<>();
    
    for(int i = 0; i < n; i++){
      String s = sc.next();
      if(hs.containsKey(s)){
        hs.put(s, hs.get(s) + 1);
      }else{
        hs.put(s, 1);
      }
    }
    
    int c = 0;
    for(var p : hs.entrySet()){
      if(c < p.getValue()) c = p.getValue();
    }
    Object[] keys = hs.keySet().toArray();
    Arrays.sort(keys);
    for(var s : keys){
      if(hs.get(s) == c) out.println(s);
    }

    out.close();
  }
}