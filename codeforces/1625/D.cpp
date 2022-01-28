#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int topBit(int p){
  int x = 0;
  while(p){
    x++;
    p >>= 1;
  }
  return x;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, k; cin >> n >> k;
  vector<pair<int, int>> a(n);
  for(int i = 0; i < n; i++){
    int v; cin >> v;
    a[i] = {topBit(v), v};
  }
  sort(all(a), greater<pair<int, int>>());

  int ans = 0;

  int l = 0, r = n;
  while(r - l > 1){
    int m = l + (r - l) / 2;
    vector<bool> v(30, 0);

    // 
  }
}