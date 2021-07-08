import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.nextLine());

    // String[] a_str = sc.nextLine().split("\\s+");
    int[] a_arr = new int[n];
    for(int i = 0; i < n; i++) a_arr[i] = Integer.parseInt(sc.next());
    sc.nextLine();

    Arrays.sort(a_arr);

    int q = Integer.parseInt(sc.nextLine());
    for(int i = 0; i < q; i++){
      int b = Integer.parseInt(sc.nextLine());
      // b:search
      int res = Arrays.binarySearch(a_arr, b);
      int p = (res >= 0) ? res : ~res;
      // -2 ~ 2
      int ans = Integer.MAX_VALUE;
      for(int j = p - 2; j <= p + 2; j++){
        if(j >= 0 && j < n){
          ans = Math.min(ans, Math.abs(b - a_arr[j]));
        }
      }
      System.out.println(ans);
    }

    sc.close();
  }
}