#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x, y; cin >> n >> x >> y;
  x--, y--;

  int dist = y - x - 1;

  // l->rの距離はr - l(x->yを使わない場合)

  vector<int> anslist(n, 0);

  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      int res = j - i;
      // x->yを使えるか？
      res = min(res, abs(x - i) + abs(j - y) + 1);
      anslist[res]++;
    }
  }
  
  for(int i = 1; i < n; i++){
    cout << anslist[i] << endl;
  }

}