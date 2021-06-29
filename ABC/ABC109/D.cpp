#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

ll modv = 1000000007;

int main(){
  int h, w; cin >> h >> w;
  // 奇数ならば右、右端は下へ
  vector<vector<int>> a(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> a[i][j];

  queue<vector<int>> steps;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(a[i][j] % 2){
        // 右端？
        if(j + 1 == w && i + 1 != h){
          // 下へ
          a[i + 1][j]++, a[i][j]--;
          steps.push({i + 1, j + 1, i + 2, j + 1});
        }else if(j + 1 < w){
          // 右へ
          a[i][j + 1]++, a[i][j]--;
          steps.push({i + 1, j + 1, i + 1, j + 2});
        }
      }
    }
  }
  
  cout << steps.size() << endl;
  while(!steps.empty()){
    auto x = steps.front();
    cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;
    steps.pop();
  }
}