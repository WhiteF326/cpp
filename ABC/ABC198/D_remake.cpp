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

int main(){
  vector<string> s(3);
  for(int i = 0; i < 3; i++) cin >> s[i];
  set<char> posx;
  for(string sc : s) for(char c : sc) posx.insert(c);
  if(posx.size() > 10){
    cout << "UNSOLVABLE" << endl;
    return 0;
  }
  
  vector<ll> weight(10, 1);
  for(int i = 1; i < 10; i++) weight[i] = weight[i - 1] * 10LL;

  vector<char> posx_ar(all(posx));
  vector<vector<int>> phr(3, vector<int>(0));
  for(int i = 0; i < 3; i++){
    for(char c : s[i]){
      phr[i].push_back(find(all(posx_ar), c) - posx_ar.begin());
    }
    reverse(all(phr[i]));
  }

  vector<ll> perm = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  do{
    bool flg = true;
    vector<ll> dec(3, 0);
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < phr[i].size(); j++){
        if(j == phr[i].size() - 1 && !perm[phr[i][j]]){
          flg = false;
          break;
        }
        dec[i] += weight[j] * perm[phr[i][j]];
      }
    }
    if(!flg) continue;
    if(dec[0] + dec[1] == dec[2]){
      for(ll val : dec) cout << val << endl;
      return 0;
    }
  }while(next_permutation(all(perm)));

  cout << "UNSOLVABLE" << endl;
}