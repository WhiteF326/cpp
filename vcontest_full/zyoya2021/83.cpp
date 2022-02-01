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
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<int> p(n);
  aryin(p, n);

  queue<int> act;

  int pos = 0;
  for(int i = 0; i < n; i++){
    if(p[i] == i + 1){
      pos++;
      continue;
    }else if(pos != p[i] - 1){
      continue;
    }else{
      for(int j = i - 1; j >= pos; j--){
        swap(p[j], p[j + 1]);
        act.push(j);
      }
      for(int j = pos; j < i; j++){
        if(p[j] != j + 1){
          cout << -1 << endl;
          return 0;
        }
      }
      pos = i;
    }
  }

  if(act.size() != n - 1){
    cout << -1 << endl;
  }else{
    for(int i = 0; i < n - 1; i++){
      cout << act.front() + 1 << endl;
      act.pop();
    }
  }
}