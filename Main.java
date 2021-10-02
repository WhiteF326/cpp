import java.util.*;


public class Main {
    public static void main(String[] args) {
        // 自分の得意な言語で
        // Let's チャレンジ！！
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int m = n * 2;
        
        if(n > 18){
            System.out.println(0);
            sc.close();
            return;
        }
        
        int ans = 0;
        for(int i = 0; i < (1 << m); i++){
            TreeSet<Integer> a = new TreeSet<>();
            for(int j = 0; j < m; j++) a.add(j);
            TreeSet<Integer> b = new TreeSet<>();
            
            for(int j = 0; j < m; j++){
                if((i & (1 << j)) != 0){
                    a.remove(j);
                    b.add(j);
                }
            }

            // System.out.println(b.size());
            
            if(a.size() != b.size()) continue;
            
            int[] ar = a.stream().mapToInt(Number::intValue).toArray();
            int[] br = b.stream().mapToInt(Number::intValue).toArray();
            
            int diffsum = 0;
            for(int j = 0; j < n; j++){
                diffsum += (int)Math.abs(ar[j] - br[j]);
            }

            if(diffsum <= k) ans++;
        }

        System.out.println(ans);

        sc.close();
    }
}