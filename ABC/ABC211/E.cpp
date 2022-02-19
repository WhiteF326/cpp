#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int n, k;
vector<int> col(64, 0);
set<ll> pst;
set<ll> st;

void dfs(ll v, int d){
  if(d == k){
    st.insert(v);
    return;
  }
  pst.insert(v);
  
  for(int i = 0; i < n * n; i++){
    if((v & (1LL << i)) == 0) continue;
    int cy = i / n;
    int cx = i % n;

    // 上
    if(cy > 0 && col[i - n] == 0 && ((v & (1LL << (i - n))) == 0)){
      if(pst.find(v | (1LL << (i - n))) == pst.end()){
        dfs(v | (1LL << (i - n)), d + 1);
      }
    }
    // 右
    if(cx < n - 1 && col[i + 1] == 0 && ((v & (1LL << (i + 1))) == 0)){
      if(pst.find(v | (1LL << (i + 1))) == pst.end()){
        dfs(v | (1LL << (i + 1)), d + 1);
      }
    }
    // 下
    if(cy < n - 1 && col[i + n] == 0 && ((v & (1LL << (i + n))) == 0)){
      if(pst.find(v | (1LL << (i + n))) == pst.end()){
        dfs(v | (1LL << (i + n)), d + 1);
      }
    }
    // 左
    if(cx > 0 && col[i - 1] == 0 && ((v & (1LL << (i - 1))) == 0)){
      if(pst.find(v | (1LL << (i - 1))) == pst.end()){
        dfs(v | (1LL << (i - 1)), d + 1);
      }
    }
  }
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> n;
  cin >> k;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < n; j++){
      if(s[j] == '#'){
        col[i * n + j] = 1;
      }
    }
  }

  for(int i = 0; i < n * n; i++){
    if(!col[i]) dfs(1LL << i, 1);
  }
  cout << st.size() << endl;
}
