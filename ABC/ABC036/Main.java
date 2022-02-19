import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    
    int n = sc.nextInt();
    int[] a = new int[n];
    
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    
    TreeMap<Integer, Integer> treeMap = new TreeMap<>();
    
    for(int i = 0; i < n; i++) {
      treeMap.put(a[i], 1);
    }
    
    int ctr = 0;
    for(var ent : treeMap.entrySet()){
      treeMap.put(ent.getKey(), ctr);
      ctr++;
    }

    for(int i = 0; i < n; i++){
      System.out.println(treeMap.get(a[i]));
    }
    
    sc.close();
  }
}
