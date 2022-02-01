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


int fibonacci(int x){
  if(x == 1){
    return 1;
  }else if(x == 2){
    return 1;
  }else{
    return fibonacci(x - 1) + fibonacci(x - 2);
  }
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n; cin >> n;
  cout << fibonacci(n) << endl;
}