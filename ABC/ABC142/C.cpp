#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> order(n, 0);
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    order[a - 1] = i + 1;
  }
  for(int i = 0; i < n - 1; i++){
    cout << order[i] << " ";
  }cout << order.back() << endl;
}