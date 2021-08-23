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

int main(){
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  vector<int> ert(100001, 0);
  ert[1] = 1;
  for(int i = 2; i <= 100000; i++){
    if(ert[i]) continue;
    for(int j = i; j <= 100000; j += i){
      ert[j] = i;
    }
  }

  // badlist
  set<int> badlist;
  for(int i = 0; i < n; i++){
    int p = a[i];
    while(p > 1){
      badlist.insert(ert[p]);
      p /= ert[p];
    }
  }

  queue<int> anslist;
  for(int i = 1; i <= m; i++){
    int p = i;
    bool flg = true;
    set<int> prmlist;
    while(p > 1){
      prmlist.insert(ert[p]);
      p /= ert[p];
    }
    for(int v : prmlist){
      if(badlist.find(v) != badlist.end()) flg = false;
    }
    if(flg) anslist.push(i);
  }
  
  cout << anslist.size() << endl;
  while(!anslist.empty()){
    cout << anslist.front() << endl;
    anslist.pop();
  }
}