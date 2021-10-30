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


struct spr{
  public:
    ll x, y, z;
    bool exist = false;

    spr(){
      x = 0, y = 0, z = 0;
    }

    spr(ll x, ll y, ll z){
      this->x = x, this->y = y, this->z = z;
    }

    spr operator + (spr obj){
      return spr(this->x + obj.x, this->y + obj.y, this->z + obj.z);
    }

    ll getEval(){
      return this->x + this->y + this->z;
    }

    bool operator < (spr obj){
      return this->getEval() < obj.getEval();
    }

    bool operator > (spr obj){
      return this->getEval() > obj.getEval();
    }

    string tostr(){
      return to_string(x) + " " + to_string(y) + " " + to_string(z);
    }
};

int main(){
  int n, m; cin >> n >> m;
  vector<spr> cakes(n);
  for(int i = 0; i < n; i++){
    ll x, y, z; cin >> x >> y >> z;
    cakes[i] = spr(x, y, z);
  }
  vector<vector<spr>> dp(n + 1, vector<spr>(m + 1));

  dp[0][0].exist = true;

  for(int i = 0; i < n; i++){
    for(int j = 0; j <= m; j++){
      if(!dp[i][j].exist) continue;
      // 選ぶ場合
      if(j + 1 <= m){
        if(dp[i + 1][j + 1] < dp[i][j] + cakes[i]){
          dp[i + 1][j + 1] = dp[i][j] + cakes[i];
          dp[i + 1][j + 1].exist = true;
        }
      }
      // 選ばない場合
      if(dp[i + 1][j] < dp[i][j]){
        dp[i + 1][j] = dp[i][j];
        dp[i + 1][j].exist = true;
      }
    }
  }

  cout << dp[n][m].tostr() << endl;

  cout << dp[n][m].getEval() << endl;
}