import java.util.*;

// ABC079 D

class Point implements Comparable<Point>{
  long dist;
  int no;

  Point(){
    dist = 0;
    no = 0;
  }

  Point(long dist, int no){
    this.dist = dist;
    this.no = no;
  }

  @Override
  public int compareTo(Point o) {
    if(this.dist == o.dist) return 0;
    else if(this.dist > o.dist) return 1;
    else return -1;
  }
}

class Main{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int h = sc.nextInt();
    int w = sc.nextInt();
    int[][] c = new int[10][10];
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        c[i][j] = sc.nextInt();
      }
    }

    int[] aCnt = new int[10];

    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        int a = sc.nextInt();
        if(a != -1) aCnt[a]++;
      }
    }

    long[] minmp = new long[10];
    for(int i = 0; i < 10; i++){
      // 数 i から 1 に書き換えるための最小の魔力を求めます
      long[] dist = new long[10];
      for(int j = 0; j < 10; j++){
        dist[j] = Integer.MAX_VALUE;
      }
      dist[i] = 0;
      
      Queue<Point> q = new PriorityQueue<Point>();
      q.add(new Point(0, i));
      while(!q.isEmpty()){
        Point dest = q.poll();

        for(int j = 0; j < 10; j++){
          if(dist[j] > dest.dist + c[dest.no][j]){
            dist[j] = dest.dist + (long)c[dest.no][j];
            q.add(new Point(dist[j], j));
          }
        }
      }

      minmp[i] = dist[1];
    }

    long ans = 0;
    for(int i = 0; i < 10; i++){
      ans += aCnt[i] * minmp[i];
    }

    System.out.println(ans);

    sc.close();
  }
}
