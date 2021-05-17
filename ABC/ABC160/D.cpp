#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x, y; cin >> n >> x >> y;
  x--, y--;

  int dist = y - x - 1;

  // l->rの距離はr - l(x->yを使わない場合)

  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; i < n; i++){
      int res = j - i;
      // x->yを使えるか？
      if(i <= x && y <= j){
        // 利用する
        res -= dist;
      }
    }
  }

}