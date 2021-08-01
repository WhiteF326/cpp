#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  sort(all(b));
  
  vector<int> trg(n);
  for(int i = 0; i < n; i++) trg[i] = a[0] ^ b[i];
  set<int> ans_pre;
  priority_queue<int, vector<int>, greater<int>> anslist;

  for(int i = 0; i < n; i++){
    vector<int> c(n);
    for(int j = 0; j < n; j++){
      c[j] = a[j] ^ trg[i];
    }
    sort(all(c));
    bool flg = true;
    for(int j = 0; j < n; j++){
      if(b[j] != c[j]) flg = false;
    }
    if(flg) ans_pre.insert(trg[i]);
  }
  for(int x : ans_pre) anslist.push(x);

  cout << anslist.size() << endl;
  while(!anslist.empty()){
    cout << anslist.top() << endl;
    anslist.pop();
  }
}