#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


vector<int> xd = {
  -1, 1, -2, 2, -2, 2, -1, 1
};
vector<int> yd = {
  2, 2, 1, 1, -1, -1, -2, -2
};

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  for(int i = 0; i < 8; i++){
    int dx = x1 + xd[i];
    int dy = y1 + yd[i];

    int vx = (dx - x2) * (dx - x2);
    int vy = (dy - y2) * (dy - y2);

    if(vx + vy == 5){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}
