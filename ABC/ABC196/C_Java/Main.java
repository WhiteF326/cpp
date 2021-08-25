package ABC.ABC196.C_Java;

import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        int ans = 0;
        for(int i = 1; i < 1000000; i++){
            String comp = String.valueOf(i) + String.valueOf(i);
            Long compval = Long.valueOf(comp);
            if(compval <= n){
                ans++;
            }else break;
        }
        System.out.println(ans);
        sc.close();
        return;
    }
}