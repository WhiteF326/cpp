#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  vector<int> v(3);
  cin >> v[0] >> v[1] >> v[2];

  int step = 0;
  while(true){
    if(v[0] == v[1] && v[1] == v[2]){
      cout << step << endl;
      return 0;
    }
    sort(v.begin(), v.end());
    if(v[1] == v[2]) v[0] += 2;
    else v[0]++, v[1]++;
    step++;
  }
}