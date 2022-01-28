import java.util.*;

public class AssignPoints{
  int[] assign(int N, int[] results){
    int[] ex = Arrays.copyOf(results, results.length);
    Arrays.sort(ex);
    HashMap<Integer, Integer> m = new HashMap<>();

    for(int i = 0; i < N; i++){
      m.put(ex[N - 1 - i], i + 1);
    }

    int tr = 0;
    for(int i = 0; i < N; i++){
      if(results[i] == -1) tr++;
    }

    int[] ans = new int[N];
    for(int i = 0; i < N; i++){
      if(results[i] == -1){
        ans[i] = 0;
      }else{
        ans[i] = m.get(results[i]) + tr;
      }
    }

    return ans;
  }

  public static void main(String[] args) {
    AssignPoints ap = new AssignPoints();
    System.out.println(Arrays.toString(ap.assign(5, new int[] {2, 2, 2, 2, 2})));
  }
}
