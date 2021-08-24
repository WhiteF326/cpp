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

ll modv = 1000000007;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  vector<int> deq;
  deq.push_back(a[0]);
  for(int i = 1; i < n; i++){
    int v = lower_bound(all(deq), a[i]) - deq.begin();
    if(v == 0){
      deq.insert(deq.begin(), a[i]);
    }else{
      deq.pop_back();
      deq.push_back(a[i]);
    }
  }
  cout << deq.size() << endl;
}