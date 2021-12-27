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
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;

  queue<int> q;

  vector<queue<int>> s(n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - 1; j++){
      int v; cin >> v;
      s[i].push(v - 1);
    }
  }

  for(int i = 0; i < n; i++){
    if(s[s[i].front()].front() == i && s[i].front() > i){
      q.push(i);
    }
  }

  int work = n * (n - 1) / 2;
  int day = 1;
  vector<bool> used(n, false);
  while(work){
    if(q.empty()){
      cout << -1 << endl;
      return 0;
    }

    int act = q.front();
    q.pop();

    int with = s[act].front();

    if(used[act] || used[with]){
      day++;
      fill(all(used), false);
    }
    used[act] = true;
    used[with] = true;

    s[act].pop();
    if(!s[act].empty()){
      int aw = s[act].front();
      if(s[aw].front() == act){
        q.push(min(act, aw));
      }
    }
    s[with].pop();
    if(!s[with].empty()){
      int ww = s[with].front();
      if(s[ww].front() == with){
        q.push(min(with, ww));
      }
    }

    work--;
  }

  cout << day << endl;
}