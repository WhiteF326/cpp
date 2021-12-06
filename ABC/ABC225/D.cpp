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


int main(){
  int n, q; cin >> n >> q;

  vector<pair<int, int>> fb(n, mp(-1, -1));
  query(q){
    int t; cin >> t;
    if(t == 1){
      int x, y; cin >> x >> y;
      x--, y--;
      fb[x].second = y;
      fb[y].first = x;
    }else if(t == 2){
      int x, y; cin >> x >> y;
      x--, y--;
      fb[x].second = -1;
      fb[y].first = -1;
    }else{
      int x; cin >> x;
      x--;
      int s = x;
      while(fb[s].first != -1) s = fb[s].first;
      queue<int> anslist;
      while(fb[s].second != -1){
        anslist.push(s);
        s = fb[s].second;
      }
      anslist.push(s);
      cout << anslist.size() << " ";
      while(!anslist.empty()){
        cout << anslist.front() + 1 << " ";
        anslist.pop();
      }cout << endl;
    }
  }
}