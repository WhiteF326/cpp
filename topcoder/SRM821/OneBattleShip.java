import java.util.*;

public class OneBattleShip{
  String[] hit(String[] grid){
    int h = grid.length;
    int w = grid[0].length();
    boolean[][] stage = new boolean[h][w];
    int n = 0;
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        if(grid[i].charAt(j) == '.'){
          stage[i][j] = true;
          n++;
        }
      }
    }

    String[] ans = Arrays.copyOf(grid, grid.length);

    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        // System.out.printf("%d %d %d %d\n", maxh, maxw, i, j);
        
      }
    }
    return ans;
  }
}