import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int k = sc.nextInt() - 1;
    int[] p = new int[n];
    for(int i = 0; i < n; i++){
      for(int j = 0; j < 3; j++) p[i] += Integer.parseInt(sc.next());
    }

    int[] d = Arrays.copyOf(p, p.length);

    Arrays.sort(p);
    int lowest = p[n - 1 - k];

    for(int i = 0; i < n; i++){
      if(d[i] + 300 >= lowest) System.out.println("Yes");
      else System.out.println("No");
    }

    sc.close();
  }
}