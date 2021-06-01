#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, k, q; cin >> n >> k >> q;
  vector<int> points(n, k - q);
  for(int i = 0; i < q; i++){
    int a; cin >> a;
    points[a - 1]++;
  }
  for(int i = 0; i < n; i++){
    if(points[i] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}