import java.util.*;

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    // 入力
    int n = sc.nextInt();
    int m = sc.nextInt();

    boolean[] visited = new boolean[n]; // 既に訪れたか？
    ArrayList<ArrayList<Integer>> roots = new ArrayList<ArrayList<Integer>>(); // グラフ本体

    // 初期化
    int[] dist = new int[n]; // 開始点からみた最短距離
    for (int i = 0; i < n; i++) {
      roots.add(new ArrayList<Integer>());
      visited[i] = false;
    }
    visited[0] = true; // 開始点は既に「訪れた」
    dist[0] = 0; // 開始点の距離は0

    // 入力
    for (int i = 0; i < m; i++) {
      int a = sc.nextInt(), b = sc.nextInt();
      a--;
      b--;
      roots.get(a).add(b);
    }

    // ここからBFS本体
    Deque<Integer> stack = new ArrayDeque<>();
    stack.push(0); // 開始点は最初にpushする
    while (stack.size() > 0) {
      int point = stack.pop();
      for (int i = 0; i < roots.get(point).size(); i++) {
        if (visited[roots.get(point).get(i)] == false) {
          visited[roots.get(point).get(i)] = true;          // 訪れた
          dist[roots.get(point).get(i)] = dist[point] + 1;  // 最短距離を入れる
          stack.push(roots.get(point).get(i));              // 次の探索位置をpush
        }
      }
    }

    // 結果
    System.out.println(dist[n - 1] == 2 ? "POSSIBLE" : "IMPOSSIBLE");
    sc.close();
  }
}