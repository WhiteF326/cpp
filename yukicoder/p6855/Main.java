package yukicoder.p6855;
import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.next());
    int[] a = new int[n];
    for(int i = 0; i < n; i++) a[i] = Integer.parseInt(sc.next());

    int[] spl = new int[1000001];
    spl[1] = 1;
    for(int i = 2; i <= 1000000; i++){
      if(spl[i] != 0) continue;
      for(int j = i; j <= 1000000; j += i){
        spl[j] = i;
      }
    }

    int[] grundy = new int[n];
    for(int i = 0; i < n; i++){
      while(a[i] > 1){
        a[i] /= spl[a[i]];
        grundy[i]++;
      }
    }

    int nimber = 0;
    for(int i = 0; i < n; i++){
      nimber = nimber ^ grundy[i];
    }
    if(nimber == 0) System.out.println("black");
    else System.out.println("white");
    sc.close();
  }
}