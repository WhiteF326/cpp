package ABC.ABC197.C_Java;
import java.util.*;

class Main{

    public static void main(String[] args){
        //
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] values = new int[n];
        for(int i = 0; i < n; i++) values[i] = sc.nextInt();
        long ans = Long.MAX_VALUE;
        if(n == 1){
            System.out.println(values[0]);
        }else{
            for(int i = 1; i < Math.pow(2, n -1); i++){
                long res = 0, tmp = 0;
                for(int j = 0; j < n; j++){
                    tmp = tmp | values[j];
                    int bitPointer = (int)Math.pow(2, j);
                    if((i & bitPointer) != 0){
                        res = res ^ tmp;
                        tmp = 0;
                    }
                }
                res = res ^ tmp;
                ans = Math.min(ans, res);
            }
            System.out.println(ans);
        }
        sc.close();
    }
}