package ARC.ARC006.B_Java;
import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt(), l = sc.nextInt();
    String[] amida = new String[l];
    sc.nextLine();
    for(int i = 0; i < l; i++){
      amida[i] = sc.nextLine();
    }
    String y = sc.nextLine();
    //y文字列を〇の位置数字へコンバート
    int yPos = 0;
    for(int i = 0; i < n * 2 - 1; i++){
      if(y.substring(i, i + 1).equals("o")){
        yPos = i / 2; break;
      }
    }
    int[][] amiVal = new int[l][n];
    //左に横線は-1, 右に横線は1と保持する
    for(int i = 0; i < l; i++){
      for(int j = 0; j < n; j++){
        if(j != 0){
          if(amida[i].substring(2 * j - 1, 2 * j).equals("-")){
            amiVal[i][j] = -1;
          }
        }
        if(j != n - 1){
          if(amida[i].substring(2 * j + 1, 2 * j + 2).equals("-")){
            amiVal[i][j] = 1;
          }
        }
      }
    }
    //当然ながら逆から見る
    for(int depth = l - 1; depth >= 0; depth--){
      yPos += amiVal[depth][yPos];
    }
    System.out.println(yPos + 1);
    sc.close();
  }
}