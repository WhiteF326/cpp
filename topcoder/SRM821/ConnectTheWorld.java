import java.util.*;

public class ConnectTheWorld {
  String[] connect(String[] terminalA, String[] terminalB, String[] isolated){
    int n = terminalA.length;
    int m = terminalB.length;
    
    HashSet<String> hs = new HashSet<>();
    for(int i = 0; i < n; i++){
      hs.add(terminalA[i]);
    }
    for(int i = 0; i < m; i++){
      hs.add(terminalB[i]);
    }

    int[] ti = new int[n];
    int[] tj = new int[m];
    var hl = hs.toArray();
    for(int i = 0; i < n; i++){
      for(int j = 0; j < hl.length; j++){
        if(hl[j] == terminalA[i]){
          ti[i] = j;
        }
      }
    }
    for(int i = 0; i < m; i++){
      for(int j = 0; j < hl.length; j++){
        if(hl[j] == terminalA[i]){
          tj[i] = j;
        }
      }
    }

    int[] ctr = new int[hl.length];

    int v = hl.length;
    int mx = 0;
    for(int i = 0; i < n; i++){
      ctr[ti[i]]++;
      ctr[tj[i]]++;
      if(mx < ctr[ti[i]]) mx = ctr[ti[i]];
      if(mx < ctr[tj[i]]) mx = ctr[tj[i]];
    }

    ArrayList<String> al = new ArrayList<>();

    for(String s : isolated){
      boolean flg = false;
      for(int i = 0; i < v; i++){
        if(ctr[i] != mx){
          al.add((String)hl[i]);
          al.add(s);
          ctr[i]++;
          flg = true;
          break;
        }
      }
      if(!flg){
        String[] ans = new String[0];
        return ans;
      }
    }

    String[] ans = new String[al.size()];
    for(int i = 0; i < al.size(); i++){
      ans[i] = al.get(i);
    }
    return ans;
  }
}
