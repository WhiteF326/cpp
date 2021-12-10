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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int trnd(){
  return (rand() % 32768) * 32768 + (rand() % 32768);
}

ll ltrnd(){
  return (ll)trnd() * (ll)trnd() + (ll)trnd();
}

int main(){
  for(int i = 2; i <= 2; i++){
    srand((unsigned)time(NULL));

    string filename = "02_seed_";
    filename += to_string(i);
    filename += ".txt";

    ofstream ofs(filename);

    // 辺に乱数を与えながら木を作る クエリを作る
    int n = 2;

    dsu d(n);
    vector<vector<ll>> edges(0);
    vector<vector<ll>> re_edges(0);

    for(int i = 0; i < 5 * n; i++){
      int l = trnd() % n;
      int r = trnd() % n;

      edges.push_back({l, r});
    }

    for(auto s : edges){
      int l = s[0], r = s[1];
      if(d.same(l, r)) continue;
      ll a = ltrnd() % 1000000000;
      re_edges.push_back({l + 1, r + 1, a});
      d.merge(l, r);
    }

    auto x = d.groups();
    for(int i = 0; i < x.size() - 1; i++){
      int l = x[i][0], r = x[i + 1][0];
      ll a = ltrnd() % 1000000000;
      re_edges.push_back({l + 1, r + 1, 1});
      d.merge(l, r);
    }

    cout << d.groups().size() << endl;

    ofs << n << endl;
    for(int i = 0; i < n - 1; i++){
      ofs << re_edges[i][0] << " " << re_edges[i][1] << " " << re_edges[i][2] << endl;
    }
  }
}