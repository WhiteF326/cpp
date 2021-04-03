package Other.APG4b;
import java.util.*;

class EX18{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();

        // initialization
        String[][] res = new String[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 0; j++) res[i][j] = "-";
        }

        // input
        for(int i = 0; i < m; i++){
            int a = sc.nextInt(), b = sc.nextInt();
            a--; b--;
            res[a][b] = "o";
            res[b][a] = "x";
        }

        //output
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 0; j++)System.out.print(res[i][j]);
            System.out.println();
        }
        sc.close();
    }
}