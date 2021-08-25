import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    
    int n = Integer.parseInt(sc.next());
    if (n % 4 == 0){
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
    
    sc.close();
  }
}