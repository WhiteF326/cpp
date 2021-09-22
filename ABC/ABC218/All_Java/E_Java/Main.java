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

class UnionFind {
  int[] parent;
  int[] rank;

  public UnionFind(int n) {
    this.parent = new int[n];
    this.rank = new int[n];

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
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
    } else if (rank[xRoot] < rank[yRoot]) {
      parent[xRoot] = yRoot;
    } else {
      parent[xRoot] = yRoot;
      rank[xRoot]++;
    }
  }
}

class Edge implements Comparable<Edge> {
  int l;
  int r;
  long c;

  public Edge(int l, int r, long c) {
    this.l = l;
    this.r = r;
    this.c = c;
  }

  @Override
  public int compareTo(Edge o) {
    return (int) Math.signum(c - o.c);
  }
}

public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner(System.in);

    int n = Integer.parseInt(sc.next());
    int m = Integer.parseInt(sc.next());

    UnionFind d = new UnionFind(n);
    Edge[] g = new Edge[m];

    for (int i = 0; i < m; i++) {
      int a = Integer.parseInt(sc.next()) - 1;
      int b = Integer.parseInt(sc.next()) - 1;
      long c = Long.parseLong(sc.next());

      g[i] = new Edge(a, b, c);
    }

    Arrays.sort(g);

    long ans = 0;
    for (Edge vert : g) {
      int l = vert.l;
      int r = vert.r;

      if (d.same(l, r) && vert.c >= 0) {
        ans += vert.c;
      } else {
        d.merge(l, r);
      }
    }

    System.out.println(ans);
  }
}