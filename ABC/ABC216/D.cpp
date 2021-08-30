#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<queue<int>> qr(m);
  for(int i = 0; i < m; i++){
    int k; cin >> k;
    for(int j = 0; j < k; j++){
      int a; cin >> a;
      qr[i].push(a - 1);
    }
  }

  vector<vector<int>> cnt(n);
  for(int i = 0; i < m; i++){
    cnt[qr[i].front()].push_back(i);
  }
  queue<int> pr;
  for(int i = 0; i < n; i++){
    if(cnt[i].size() == 2) pr.push(i);
  }

  int last = n;
  while(pr.size()){
    int dest = pr.front();
    pr.pop();
    last--;
    for(int x : cnt[dest]){
      qr[x].pop();
      if(qr[x].size()){
        cnt[qr[x].front()].push_back(x);
        if(cnt[qr[x].front()].size() == 2) pr.push(qr[x].front());
      }
    }
  }

  if(last) cout << "No" << endl;
  else cout << "Yes" << endl;
}