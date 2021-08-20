#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int cv(vector<ll> a, vector<ll> b){
  // a is bigger then 1
  if(a.size() > b.size()) return 1;
  else if(a.size() < b.size()) return -1;
  else{
    for(int i = 0; i < a.size(); i++){
      if(a[i] > b[i]) return 1;
      else if(a[i] < b[i]) return -1;
    }
    return 0;
  }
}

string vect_lis(vector<ll> x, string sep){
  string ans = "";
  for(int i = 0; i < x.size() - 1; i++) ans += to_string(x[i]) + sep;
  return ans + to_string(x[x.size() - 1]);
}

int main(){
  string x; cin >> x;
  ll m; cin >> m;
  ll right = m;
  ll base = *max_element(all(x)) - '0' + 1;
  ll left = base;
  ll mid = 0;

  if(x.size() == 1){
    ll xi = x[0] - '0';
    if(xi <= m){
      cout << 1 << endl;
    }else{
      cout << 0 << endl;
    }
    return 0;
  }

  // make vector
  vector<ll> xlist(x.size());
  for(int i = 0; i < x.size(); i++){
    xlist[i] = x[i] - '0';
  }

  while(right >= left){
    mid = left + (right - left) / 2;
    // mをmid進数にする
    vector<ll> mmid;
    ll ch = m;
    while(ch > 0){
      mmid.push_back(ch % mid);
      ch /= mid;
    }
    reverse(all(mmid));
    // cout << mid << " " << vect_lis(mmid, ",") << endl;

    int res = cv(xlist, mmid);
    if(res == 1){
      right = mid - 1;
    }else if(res == -1){
      left = mid + 1;
    }else{
      break;
    }
  }

  ll ans = mid - 3;
  // 近傍-2～2を探索する
  for(ll i = max(base, mid - 2); i <= mid + 2; i++){
    vector<ll> imid;
    ll ch = m;
    while(ch > 0){
      imid.push_back(ch % i);
      ch /= i;
    }
    reverse(all(imid));
    
    int res = cv(xlist, imid);
    if(res < 1) ans = i;
  }

  cout << max(ans - base + 1, 0LL) << endl;
}