import java.util.*;

class Main{
    static int n;
    static boolean[] used = {false, false, false, false, false, false, false, false};
    
    static ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
    static Stack<Integer> line = new Stack<Integer>();
    
    public static int dfs(int depth, int p){
        line.push(p);
        if(depth == n - 1){
            ArrayList<Integer> rst = new ArrayList<Integer>();
            line.forEach(r -> rst.add(r));
            res.add(rst);
            line.pop();
            return 0;
        }
        used[p] = true;
        for(int i = 0; i < n; i++){
            if(!used[i]) dfs(depth + 1, i);
        }
        used[p] = false;
        line.pop();
        return 0;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        ArrayList<Integer> p = new ArrayList<Integer>();
        ArrayList<Integer> q = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            p.add(sc.nextInt() - 1);
        }
        for(int i = 0; i < n; i++){
            q.add(sc.nextInt() - 1);
        }
        for(int i = 0; i < n; i++){
            dfs(0, i);
        }
        int ppos = 0, qpos = 0;
        for(int i = 0; i < res.size(); i++){
            boolean flg = true;
            for(int j = 0; j < n; j++){
                if(res.get(i).get(j) != p.get(j)) flg = false;
            }
            if(flg) ppos = i;
            flg = true;
            for(int j = 0; j < n; j++){
                if(res.get(i).get(j) != q.get(j)) flg = false;
            }
            if(flg) qpos = i;
        }
        System.out.println((int)Math.abs(ppos - qpos));
        sc.close();
    }
}