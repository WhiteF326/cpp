import java.util.Scanner;

class Main{
  public static void main(String[] args) {
    int[] e = new int[100001];
    for(int i = 2; i <= 100000; i++) e[i] = 1;
    for(int i = 2; i * i <= 100000; i++){
      if(e[i] == 0) continue;
      for(int j = i + i; j <= 100000; j += i){
        e[j] = 0;
      }
    }

    int[] lv = new int[100001];
    for(int i = 3; i <= 100000; i += 2){
      if(e[i] == 1 && e[(i + 1) / 2] == 1){
        lv[i] = 1;
      }
    }

    for(int i = 1; i <= 100000; i++) lv[i] += lv[i - 1];

    Scanner sc = new Scanner(System.in);

    int q = sc.nextInt();

    for(int _q = 0; _q < q; _q++){
      int l = sc.nextInt();
      int r = sc.nextInt();
      int ans = lv[r];
      if(l >= 1) ans -= lv[l - 1];

      System.out.println(ans);
    }

    sc.close();
  }
}