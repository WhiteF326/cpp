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
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)


constexpr ll mods[] = {916471357, 936547751, 951231241, 976977707};
constexpr ll bases[] = {10007, 15679, 20693, 25693};
constexpr ll invl[] = {116218862, 565608180, 738304014, 368310671};


struct RollingHash {
  string s;
  vector<vector<ll>> hash, pows, invs;

  RollingHash(string s){
    s = (char)0 + s;
    this->s = s;
    hash.resize(4);
    pows.resize(4);
    invs.resize(4);
    for(int i = 0; i < 4; i++){
      hash[i].resize(s.length());
      pows[i].resize(s.length());
      invs[i].resize(s.length());
      pows[i][0] = 1;
      invs[i][0] = 1;
      hash[i][0] = (int)s[0];
      for(int j = 1; j < s.length(); j++){
        pows[i][j] = (pows[i][j - 1] * bases[i]) % mods[i];
        invs[i][j] = (invs[i][j - 1] * invl[i]) % mods[i];
        hash[i][j] = (pows[i][j] * (int)s[j]) % mods[i];
        hash[i][j] = (hash[i][j] + hash[i][j - 1]) % mods[i];
      }
    }
  }

  vector<ll> get(int l, int r){
    vector<ll> hashes(4, 0);
    for(int i = 0; i < 4; i++){
      hashes[i] = hash[i][r] - hash[i][l] + mods[i];
      hashes[i] = (hashes[i] * invs[i][l]) % mods[i];
    }
    return hashes;
  }

  static bool sameHash(vector<ll> a, vector<ll> b){
    bool ans = true;
    for(int i = 0; i < 4; i++){
      if(a[i] != b[i]) ans = false;
    }
    return ans;
  }
};


int main(){
  int n; cin >> n;
  string s; cin >> s;
  string t = "ABC";
  RollingHash sh(s), th(t);
  int ans = 0;
  for(int i = 0; i <= n - t.length(); i++){
    if(RollingHash::sameHash(sh.get(i, i + t.length()), th.get(0, t.length()))){
      ans++;
    }
  }
  cout << ans << endl;
}