// this problem sucks I'll never do this again

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  ll n; cin >> n;
  ll m = n;
  map<ll, int> prm;
  for(int i = 2; i <= sqrt(n); i++){
    while(m % i == 0){
      m /= i;
      prm[i]++;
    }
  }
  if(m != 1) prm[m]++;
  int ans = 0;
  for(auto p : prm){
    int tmp = 0, c = 0;
    while(true){
      c++;
      tmp += c;
      if(tmp == p.second){
        ans += c;
        break;
      }else if(tmp > p.second){
        ans += c - 1;
        break;
      }
    }
  }
  cout << ans << endl;
}
