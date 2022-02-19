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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;

  // list of who want to match
  vector<queue<int>> s(n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - 1; j++){
      int v; cin >> v;
      s[i].push(v - 1);
    }
  }

  // 対戦待ちのリスト
  queue<int> q;

  for(int i = 0; i < n; i++){
    // make a first pair
    if(s[s[i].front()].front() == i && s[i].front() > i){
      q.push(i);
    }
  }

  int work = n * (n - 1) / 2;
  int day = 1;
  // day 日目にもう誰かと対戦したか？
  vector<bool> mtc(n, false);

  while(work--){
    if(q.empty()){
      cout << -1 << endl;
      return 0;
    }

    int a = q.front();
    int b = s[a].front();
    q.pop();

    if(mtc[a] || mtc[b]){
      // その日を終了させる
      day++;
      fill(all(mtc), false);
    }
    mtc[a] = true;
    mtc[b] = true;

    s[a].pop();
    if(!s[a].empty()){
      int aw = s[a].front();
      if(s[aw].front() == a){
        q.push(min(a, aw));
      }
    }
    s[b].pop();
    if(!s[b].empty()){
      int bw = s[b].front();
      if(s[bw].front() == b){
        q.push(min(b, bw));
      }
    }
  }

  cout << day << endl;
}
