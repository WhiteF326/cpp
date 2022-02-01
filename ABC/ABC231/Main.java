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
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt(), m = sc.nextInt();
    int[] inc = new int[n];
    List<List<Integer>> list = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      list.add(new ArrayList<>());
    }

    for (int i = 0; i < m; i++) {
      int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
      inc[a]++;
      inc[b]++;
      list.get(a).add(b);
      list.get(b).add(a);
    }

    for (int i : inc) {
      if (i > 2) {
        System.out.println("No");
        return;
      }
    }

    Queue<Integer> queue = new ArrayDeque<>();
    boolean[] visited = new boolean[n];
    int[] depth = new int[n];
    for(int i = 0; i < n; i++){
      depth[i] = Integer.MAX_VALUE;
    }
    for(int i = 0; i < n; i++){
      if(visited[i]) continue;
      visited[i] = true;
      depth[i] = 0;
      queue.add(i);

      while(!queue.isEmpty()){
        int dest = queue.poll();

        for(int v : list.get(dest)){
          if(depth[dest] <= depth[v] && visited[v]){
            System.out.println("No");
            return;
          }else if(!visited[v]){
            visited[v] = true;
            depth[v] = depth[dest] + 1;
            queue.add(v);
          }
        }
      }
    }

    System.out.println("Yes");
  }
}