package ABC.ABC210.C_Java;

import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int n = Integer.parseInt(sc.next());
    int k = Integer.parseInt(sc.next());
    int[] c = new int[n];
    for(int i = 0; i < n; i++) c[i] = Integer.parseInt(sc.next());
    HashMap<Integer, Integer> app = new HashMap<>();
    int ans = 0;

    // first
    for(int i = 0; i < k; i++){
      if(app.get(c[i]) == null){
        app.put(c[i], 1);
      }else{
        app.put(c[i], app.get(c[i]) + 1);
      }
    }
    ans = app.size();

    // next~
    for(int i = k; i < n; i++){
      // delete
      app.put(c[i - k], app.get(c[i - k]) - 1);
      if(app.get(c[i - k]) == 0) app.remove(c[i - k]);

      // add
      if(app.get(c[i]) == null){
        app.put(c[i], 1);
      }else{
        app.put(c[i], app.get(c[i]) + 1);
      }

      // cal
      ans = Math.max(ans, app.size());
    }

    // end
    System.out.println(ans);

    sc.close();
  }
}