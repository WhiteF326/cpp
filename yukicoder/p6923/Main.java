import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt();
    int a = sc.nextInt(), b = sc.nextInt();
    a--; b--;
    List<List<Integer>> g = new ArrayList<List<Integer>>();

    for(int i = 0; i < n; i++){
      g.add(new ArrayList<Integer>());
    }
    for(int i = 0; i < m; i++){
      int x = sc.nextInt(), y = sc.nextInt();
      x--; y--;
      g.get(x).add(y);
      g.get(y).add(x);
    }

    Queue<Integer> q = new ArrayDeque<Integer>();
    q.add(a);
    int[] depth = new int[n];
    boolean[] visited = new boolean[n];
    for(int i = 0; i < n; i++){
      depth[i] = Integer.MAX_VALUE;
      visited[i] = false;
    }
    depth[a] = 0;
    visited[a] = true;

    while(!q.isEmpty()){
      int dest = q.poll();
      for(int v : g.get(dest)){
        if(!visited[v]){
          visited[v] = true;
          depth[v] = depth[dest] + 1;
          q.add(v);
        }
      }
    }

    if(k == depth[b]){
      System.out.println("shortest");
    }else{
      System.out.println(k - depth[b]);
    }

    sc.close();
  }
}