#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int gcd(int a, int b){
  while(b > 0){
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  // 篩の実行
  vector<int> ert(1000001, INT_MAX);
  ert[0] = 0;
  ert[1] = 1;
  for(int i = 2; i <= 1000; i++){
    if(ert[i] == INT_MAX){
      ert[i] = i;
      for(int j = i * 2; j <= 1000000; j += i){
        ert[j] = min(ert[j], i);
      }
    }
  }

  int all_gcd = a[0];
  bool isPairwise = true;
  vector<bool> cont(1000001, false);
  for(int i = 1; i < n; i++){
    all_gcd = gcd(all_gcd, a[i]);
    set<int> divs;
    while(true){
      divs.insert(ert[a[i]]);
      
    }
  }
  if(gcd(a[0], a[n - 1]) != 1) isPairwise = false;
  if(isPairwise){
    cout << "pairwise coprime" << endl;
  }else if(all_gcd == 1){
    cout << "setwise coprime" << endl;
  }else{
    cout << "not coprime" << endl;
  }
}