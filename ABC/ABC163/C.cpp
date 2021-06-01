#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int gcd(int i, int j){
  if(i % j){
    return gcd(j, i % j);
  }else return j;
}

int main(){
  int n; cin >> n;
  vector<int> cnt(n, 0);
  for(int i = 0; i < n - 1; i++){
    int x; cin >> x;
    cnt[x - 1]++;
  }
  for(int i = 0; i < n; i++){
    cout << cnt[i] << endl;
  }
}