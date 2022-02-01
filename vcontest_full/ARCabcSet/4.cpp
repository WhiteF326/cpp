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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  vector<int> a(4);
  aryin(a, 4);
  int s = accumulate(all(a), 0);
  
  for(int i = 0; i < (1 << 4); i++){
    int res = 0;
    for(int j = 0; j < 4; j++){
      if(i & (1 << j)) res += a[j];
    }
    if(s - res == res){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}