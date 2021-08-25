package Other.ACL_Beginner.C_Java;

import java.util.*;

public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt(), m = sc.nextInt();
    ArrayList<ArrayList<Integer>> gr = new ArrayList<ArrayList<Integer>>();
    for(int i = 0; i < n; i++){
      gr.add(new ArrayList<Integer>());
    }
    for(int i = 0; i < m; i++){
      int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
      gr.get(a).add(b);
      gr.get(b).add(a);
    }

    // BFS
    boolean[] visited = new boolean[n];
    for(int i = 0; i < n; i++) visited[i] = false;
    Queue<Integer> q = new ArrayDeque<Integer>();
    int ans = 0;

    for(int i = 0; i < n; i++){
      if(visited[i] == false){
        q.add(i);
        visited[i] = true;
        ans++;
        while(!q.isEmpty()){
          int dest = q.poll();
          for(int j = 0; j < gr.get(dest).size(); j++){
            if(visited[gr.get(dest).get(j)] == false){
              visited[gr.get(dest).get(j)] = true;
              q.add(gr.get(dest).get(j));
            }
          }
        }
      }
    }

    System.out.println(ans - 1);

    sc.close();
  }
}
