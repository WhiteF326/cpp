#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  map<int, int> appearance;
  for(int i = 0; i < 6; i++){
    int x; cin >> x;
    appearance[x]++;
  }
  for(int i = 1; i < 5; i++){
    if(appearance[i] > 2){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}