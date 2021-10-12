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

#define chmax(a, b) a = max(a, b)


int main(){
  int n; cin >> n;

  vector<int> def(n + 1, 1);
  for(int i = 1; i <= n / 2; i++){
    for(int j = i * 2; j <= n; j += i){
      if(def[j] < def[i] + 1) def[j] = def[i] + 1;
    }
  }

  for(int i = 1; i <= n; i++){
    cout << def[i] << " ";
  }
  cout << endl;
}