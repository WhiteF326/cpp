#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  vector<int> v(4);
  for(int i = 0; i < 4; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int t = accumulate(v.begin(), v.end(), 0);

  bool flg = false;
  do{
    for(int i = 0; i < 4; i++){
      int res = 0;
      for(int j = 0; j < i; j++){
        res += v[j];
      }
      if(t - res == res) flg = true;
    }
  }while(next_permutation(v.begin(), v.end()));
  cout << (flg ? "Yes" : "No") << endl;
}