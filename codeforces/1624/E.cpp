#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


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
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n, m; cin >> n >> m;
    vector<RollingHash> hs(n, RollingHash(""));
    for(int i = 0; i < n; i++){
      string s; cin >> s;
      hs[i] = RollingHash(s);
    }
    string t; cin >> t;
    RollingHash ht(t);

    bool ans = true;
    vector<int> d(m - 1);
    for(int i = 0; i < m - 1; i += 2){
      bool res = false;
      auto rh = ht.get(i, i + 2);
      for(int j = 0; j < n; j++){
        for(int k = 0; k < m - 1; k++){
          auto lh = hs[j].get(k, k + 2);
          cout << t.substr(i, 2) << " " << hs[j].s.substr(k + 1, 2) << endl;;
          if(RollingHash::sameHash(lh, rh)){
            res = true;
            break;
          }
        }
        if(res){
          d[i] = i;
          i++;
          break;
        }
      }

      if(!res){
        ans = false;
        break;
      }
    }

    if(ans){
      cout << m - 1 << endl;
      for(int i = 0; i < m - 1; i++){
        cout << i + 1 << " " << i + 2 << " " << d[i] + 1 << endl;
      }
    }else{
      cout << -1 << endl;
    }
  }
}