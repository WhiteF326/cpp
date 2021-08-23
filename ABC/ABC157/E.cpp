#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;

int op(int a, int b){
  return a | b;
}
int e(){
  return 0;
}

int main(){
  int n; cin >> n;
  string s; cin >> s;
  vector<int> parse(n, 0);
  for(int i = 0; i < n; i++){
    parse[i] = (1 << (s[i] - 'a'));
  }

  segtree<int, op, e> seg(parse);

  int q; cin >> q;
  queue<int> anslist;
  for(int i = 0; i < q; i++){
    int t; cin >> t;
    if(t == 1){
      int i; cin >> i; i--;
      string c; cin >> c;
      int p = (1 << (c[0] - 'a'));
      seg.set(i, p);
    }else{
      int l, r; cin >> l >> r;
      l--;
      int stat = seg.prod(l, r);
      int ans = 0;
      for(int i = 0; i < 26; i++){
        ans += (((1 << i) & stat) ? 1 : 0);
      }
      anslist.push(ans);
    }
  }
  while(!anslist.empty()){
    cout << anslist.front() << endl;
    anslist.pop();
  }
}